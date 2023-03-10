#include "separator.h"

namespace easy {
    Separator::Separator(const std::string& separator) : 
        separator_(separator)
    {
    }

    Dump& Separator::Process(Dump& dump)
    {
        GetFile(dump) << separator_;
        return dump;
    }
}