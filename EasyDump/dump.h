#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "separator.h"

namespace easy {

    class Dump {
    public:
        Dump(const std::string& path);

        template <typename T>
        Dump& operator<<(const T& element)
        {
            file_ << element;
            for (auto& component : components_)
                component->Process(*this);
            return *this;
        }

        template <>
        Dump& operator<<<Separator>(const Separator& element)
        {
            std::unique_ptr<Component> component = std::make_unique<Separator>(element);
            components_.push_back(std::move(component));
            return *this;
        }

        friend class Component;
    private:
        std::ofstream file_;
        std::vector<std::unique_ptr<Component>> components_;
    };

}

#if 0
obj << easy::BegSeparator("|") << a << b << c;
#endif