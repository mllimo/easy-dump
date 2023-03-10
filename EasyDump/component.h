#pragma once

#include <fstream>
#include <vector>

namespace easy {

    class Dump;

    class Component {
    public:
        Component() = default;
        Component(Component&&) = default;
        Component(const Component&) = default;

        virtual ~Component();
        virtual Dump& Process(Dump& dump);

    protected:
        std::ofstream& GetFile(Dump& dump);
        std::vector<std::unique_ptr<Component>>& GetComponents(Dump& dump);
    };
}