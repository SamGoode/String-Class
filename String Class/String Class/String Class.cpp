#include <iostream>
#include "String.h"

int main() {
    String test = "Sebastian";
    String buddies = "";
    String test2 = test;
    buddies.Prepend(test);
    buddies.Append(test2);

    int finds = 0;
    String find = "an";

    for (int i = 0; buddies.Find(i, find) != -1; i += buddies.Find(i, find) + 1) {
        finds++;
    }
    std::cout << finds << std::endl;

    std::cout << buddies.CStr() << std::endl;
    buddies.Replace("tian", "Sven");
    std::cout << buddies.CStr() << std::endl;

    std::cout << buddies.Find(7, "ven") << std::endl;
}
