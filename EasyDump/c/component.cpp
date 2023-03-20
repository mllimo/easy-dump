#include <EasyDump/h/component.h>
#include <EasyDump/h/dump.h>

#include <stdexcept>

namespace easy {

    Component::~Component() {}

    void Component::SetUp(Actions& actions)
    {
    }

    void Component::Process(Actions& dump)
    { 
        std::string err = "Component::";
        err += __func__;
        err += " bad call";
        throw std::runtime_error(err);
    }

}