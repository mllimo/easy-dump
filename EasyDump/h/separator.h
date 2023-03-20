#pragma once

#include <EasyDump/h/component.h>

namespace easy {
    class BegSeparator : public Component {
    public:
        using Component::Component;
        BegSeparator(const std::string& separator);
        void Process(Actions& dump) override;
        
        const std::string& GetSeparator() const;

    private:
        std::string separator_;
    };

    class EndSperator : public Component {
    public:
        EndSperator(const std::string& separator);
        void SetUp(Actions& actions) override;

    private:
        std::string separator_;
    };
}