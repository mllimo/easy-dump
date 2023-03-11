#include "separator.h"
#include "dump.h"

namespace easy {
    BegSeparator::BegSeparator(const std::string& separator) :
        separator_(separator),
        activated_(true)
    {
    }

    void BegSeparator::Process(Actions& actions)
    {
        actions.GetFile() << separator_;
    }

    const std::string& BegSeparator::GetSeparator() const
    {
        return separator_;
    }

    bool& BegSeparator::activated()
    {
        return activated_;
    }

    EndSperator::EndSperator(const std::string& separator) :
        separator_(separator)
    {
    }

    void EndSperator::Process(Actions& actions)
    {
        int i;
        for (i = 0; i < actions.GetComponents().size(); ++i) {
            if (actions.GetComponents()[i].get() == this) {
                break;
            }
        }

        if (i == actions.GetComponents().size()) return;

        for (i; i >= 0; --i) {
            auto begin_cast = dynamic_cast<BegSeparator*>(actions.GetComponents()[i].get());
            if (begin_cast != nullptr) {
                if (begin_cast->GetSeparator() == separator_) {
                    begin_cast->activated() = false;
                }
            }
        }

    }
}