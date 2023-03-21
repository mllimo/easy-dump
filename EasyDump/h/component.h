#pragma once

#include <fstream>
#include <vector>

namespace easy {

    class Actions;

    class Component {
    public:
        Component() = default;
        Component(Component&&) = default;
        Component(const Component&) = default;

        virtual ~Component();
        virtual void SetUp(Actions& actions);
        virtual void Process(Actions& actions);
    };
}