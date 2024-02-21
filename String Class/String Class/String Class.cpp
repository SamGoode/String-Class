#include <iostream>
#include "String.h"

int main() {
    String demo = "Hell";
    String demo2;
    demo2 = demo + "oh";
    demo2.Append(" Woop de ");
    demo2 += "doop";
    demo2.CharacterAt(5) = ',';
    demo2.Replace("op de doop", "rld!");
    demo2.WriteToConsole();

    std::cout << (String("testing") < String("testingsss"));
}
