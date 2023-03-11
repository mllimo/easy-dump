#include "dump.h"
#include "separator.h"

int main() {
    easy::Dump dump("C:/Users/argui/Desktop/test.txt");
    //dump << easy::BegSeparator(" | ") << 1 << 2 << 3 << 4 << easy::EndSperator(" | ") << "Buenos dias" << 2 << "\n";
    dump << "{" << easy::BegSeparator(",") << 1 << 2 << 3 << easy::EndSperator(",") << "} Hola";
}