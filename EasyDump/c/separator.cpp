#include <EasyDump/h/separator.h>
#include <EasyDump/h/dump.h>

namespace easy {
    BegSeparator::BegSeparator(const std::string& separator) :
        separator_(separator)
    {
    }

    void BegSeparator::Process(Actions& actions)
    {
        actions.GetStream() << separator_;
    }

    const std::string& BegSeparator::GetSeparator() const
    {
        return separator_;
    }

    EndSperator::EndSperator(const std::string& separator) :
        separator_(separator)
    {
    }

    void EndSperator::SetUp(Actions& actions)
    {
        int i = 0;
        for (i = (int)actions.GetComponents().size() - 1; i >= 0; --i) {
            auto begin_ptr = dynamic_cast<BegSeparator*>(actions.GetComponents()[i].get());
            if (begin_ptr != nullptr && begin_ptr->GetSeparator() == separator_) {
                actions.GetComponents().erase(actions.GetComponents().begin() + i);
                break;
            }
        }
        actions.GetComponents().pop_back();
    }
}