#include <iostream>
#include "String.h"

int main() {
    String test = String("Sebastian");
    String buddies = String(" and ");
    String test2 = String("Sven");
    buddies.Prepend(test);
    buddies.Append(test2);
    
    std::cout << test.CStr() << std::endl;
    std::cout << test.Find("tian") << std::endl;
}
