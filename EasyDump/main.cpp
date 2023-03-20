#include "dump.h"
#include "separator.h"
#include "list.h"
#include "compare.h"

#include <set>
#include <list>

int main() {
    //easy::Dump dump("C:/Users/argui/Desktop/test.txt");
    easy::Dump dump(std::cout);


    std::vector<int> a = { 1, 2, 3, 4, 5 };
    std::set<int> b = { 1, 2, 3, 4, 5 };
    std::list<int> c = { 1, 2, 3, 4, 5 };

    int pepe = 11;
    float manolo = 11.f;

    dump << "{" << easy::BegSeparator(",") << 1 << 2 << easy::EndSperator(",") << 3 << "} Hola\n";
    dump << easy::List(a) << "\n";
    dump << easy::List(b) << "\n";
    dump << easy::List(c) << "\n";
    dump << easy::Compare(a, c) << "\n";
    std::cout << "El pepe\n";



}