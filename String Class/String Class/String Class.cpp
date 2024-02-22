#include <iostream>
#include "String.h"

int main() {
    String demo;
    String demo2 = "Hell";
    String demo3 = demo2;
    std::cout << demo3.Length() << std::endl; //outputs 4
    std::cout << demo3.CharacterAt(1) << std::endl; //outputs 'e'
    std::cout << (demo3.EqualTo("Hell") && demo3.EqualTo(demo2)) << std::endl; //outputs 1 (true)
    demo3.Append(" ooh").WriteToConsole(); //outputs 'Hell ooh'
    demo3.Prepend("Whoops").WriteToConsole(); //outputs 'Whoopshell ooh'
    std::cout << demo3.CStr() << std::endl; //also outputs 'Whoopshell ooh'
    demo3.ToUpper().WriteToConsole().ToLower().WriteToConsole(); //outputs 'WHOOPSHELL OH' and then outputs 'whoopshell ooh'
    std::cout << demo3.Find("oo") << std::endl; //outputs 2
    std::cout << demo3.Find(3, "oo") << std::endl; //outputs 11
    demo3.Replace("oo", "pizza").WriteToConsole(); //outputs 'whpizzapshell pizzah'
    std::cout << (demo3 == "whpizzapshell pizzah") << std::endl; //outputs 1 (true)
    std::cout << (demo3 != "whpizzapshell pizzah") << std::endl; //outputs 0 (false)
    demo = "Hello, Steve!";
    std::cout << demo[5] << std::endl; //outputs ','
    std::cout << (demo < "gandhi") << std::endl; //outputs 0 (false)
    std::cout << (demo < "igandhi") << std::endl; //outputs 1 (true)
    demo.Replace(", Steve", "").WriteToConsole(); //outputs 'Hello!'
    (demo + " " + demo3).WriteToConsole(); //outputs 'Hello! whpizzapshell pizzah'
    demo += " I am world.";
    demo.WriteToConsole(); //outputs 'Hello! I am world."
    String input;
    input.ReadFromConsole(); //takes user input from console
    std::cout << (input == "Bob") << std::endl; //returns 1 (true) if user input was 'Bob' otherwise returns false
    input.Prepend("Hello ").WriteToConsole(); //outputs 'Hello {input}'
    demo3.ReadFromConsole(); //waits for input
}
