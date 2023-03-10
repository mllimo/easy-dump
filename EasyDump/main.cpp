#include "dump.h"
#include "separator.h"

int main() {
    easy::Dump dump("C:/Users/argui/Desktop/test.txt");
    dump << easy::Separator(" | ") << 1 << 2 << 3 << 4 << "\n";
}