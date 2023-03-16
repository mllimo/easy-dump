#include "separator.h"
#include "dump.h"

#include <iostream>

namespace easy {
    BegSeparator::BegSeparator(const std::string& separator) :
        separator_(separator),
        activated_(true)
    {
    }

    void BegSeparator::Process(Actions& actions)
    {
        if (activated_)
            actions.GetStream() << separator_;
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

    void EndSperator::SetUp(Actions& actions)
    {
        int i = 0;
        for (i = actions.GetComponents().size() - 1; i >= 0; --i) {
            auto begin_ptr = dynamic_cast<BegSeparator*>(actions.GetComponents()[i].get());
            if (begin_ptr != nullptr && begin_ptr->GetSeparator() == separator_) {
                actions.GetComponents().erase(actions.GetComponents().begin() + i);
                break;
            }
        }
        actions.GetComponents().pop_back();
    }
}