## Requirements

The requirements for this exercise can be expressed by the following:

1. The class must be able to store any types  (int, double, char[], std::string, user defined classes, and so on) and access them via std::string.
2. The class must be able to store N values in subsections of depth D, with N and D defined at runtime.
3. The class must preserve the interface of a c++ map. In fact, a C++ map can be thought as a special case of the generic map.


## Examples

// Insertion
MySpecialMap map;
map["variable"] = 42;
map["section"]["a subsection"] = std::string("this is a subsection");
map["another_section"]["another subsection"]["a double"] = 42.0;

// Output
int my_int = map["variable"];
std::string = map["section"]["a subsection"];
double my_double = map["another_section"]["another subsection"]["a double"];


You can find the article for this code [here](https://fma350.github.io/).
