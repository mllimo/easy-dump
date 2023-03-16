#include "dump.h"

namespace easy {
    Dump::Dump(std::ostream& os) :
        stream_(os)
    {
    }

    Dump::Dump(const std::string& path) :
        file_(path),
        stream_(file_)
    {
    }
}