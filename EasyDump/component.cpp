#include "component.h"
#include "dump.h"

#include <stdexcept>

namespace easy {

    Component::~Component() {}

    Dump& Component::Process(Dump& dump)
    { 
        std::string err = "Component::";
        err += __func__;
        err += " bad call";
        throw std::runtime_error(err);
        return dump; 
    }

    std::ofstream& Component::GetFile(Dump& dump)
    {
        return dump.file_;
    }

    std::vector<std::unique_ptr<Component>>& Component::GetComponents(Dump& dump)
    {
        return dump.components_;
    }
}