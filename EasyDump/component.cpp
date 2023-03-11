#include "component.h"
#include "dump.h"

#include <stdexcept>

namespace easy {

    Component::~Component() {}

    void Component::Process(Actions& dump)
    { 
        std::string err = "Component::";
        err += __func__;
        err += " bad call";
        throw std::runtime_error(err);
    }

}