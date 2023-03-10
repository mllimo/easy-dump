#pragma once

#include "component.h"

namespace easy {
    class Separator : public Component {
    public:
        using Component::Component;
        Separator(const std::string& separator);
        Dump& Process(Dump& dump) override;
    private:
        std::string separator_;
    };
}