#pragma once

#include "component.h"

namespace easy {
    class BegSeparator : public Component {
    public:
        using Component::Component;
        BegSeparator(const std::string& separator);
        void Process(Actions& dump) override;
        
        const std::string& GetSeparator() const;
        bool& activated();

    private:
        std::string separator_;
        bool activated_ = false;
    };

    class EndSperator : public Component {
    public:
        EndSperator(const std::string& separator);
        void Process(Actions& dump) override;

    private:
        std::string separator_;
    };
}