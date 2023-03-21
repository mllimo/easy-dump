# EasyDump

Simple library to easy dump information to a console, file or ostream.

## Quick Documentation

* easy::Dump dump(std::cout); It will dump to a console.
* easy::Dump dump("easy.txt"); It will dump to a file.

### Components:

* Separator: Separator will put the especified separator after each element until an easy::EndSeparator.
```cpp
// key1,key2,key3,key4,key5,key6
dump << easy::BegSeparator(",") << "key1" << "key2" << "key3" << "key4" << "key5" << "key6" << easy::EndSperator(",");

// better than
stream << "key1" << ',' <<"key2" << ',' << "key3" << ',' << "key4" << ',' << "key5" << ',' << "key6" << ',';
```
* List: It will print containers that use iterators.
```cpp
   std::vector<int> vector = { 1, 2, 3, 4, 5 };
   std::set<int> set = { 1, 2, 3, 4, 5 };
   std::list<int> list = { 1, 2, 3, 4, 5 };

   // It Will print: [1, 2, 3, 4, 5]
   dump << easy::List(vector) << "\n";
   // It Will print: [1, 2, 3, 4, 5]
   dump << easy::List(set) << "\n";
   // It Will print: [1, 2, 3, 4, 5]
   dump << easy::List(list) << "\n";
```
* Compare: Show is two variables are equal or not.
```cpp
   int my_int = 11;
   float my_float = 11.f;

   // It Will print: my_int(11) == my_float(11)
   dump << easy::Compare(my_int, my_float) << "\n";
   
   my_int = 12;

   // It Will print: my_int(12) != my_float(11)
   dump << easy::Compare(my_int, my_float) << "\n";

   // It Will print: vector([1, 2, 3, 4, 5]) == set([1, 2, 3, 4, 5])
   dump << easy::Compare(vector, set) << "\n";
```