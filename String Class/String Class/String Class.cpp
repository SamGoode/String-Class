#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"

int main() {
    //String demo;
    //String demo2 = "Hell";
    //String demo3 = demo2;
    //std::cout << demo3.Length() << std::endl; //outputs 4
    //std::cout << demo3.CharacterAt(1) << std::endl; //outputs 'e'
    //std::cout << (demo3.EqualTo("Hell") && demo3.EqualTo(demo2)) << std::endl; //outputs 1 (true)
    //demo3.Append(" ooh").WriteToConsole(); //outputs 'Hell ooh'
    //demo3.Prepend("Whoops").WriteToConsole(); //outputs 'Whoopshell ooh'
    //std::cout << demo3.CStr() << std::endl; //also outputs 'Whoopshell ooh'
    //demo3.ToUpper().WriteToConsole().ToLower().WriteToConsole(); //outputs 'WHOOPSHELL OH' and then outputs 'whoopshell ooh'
    //std::cout << demo3.Find("oo") << std::endl; //outputs 2
    //std::cout << demo3.Find(3, "oo") << std::endl; //outputs 11
    //demo3.Replace("oo", "pizza").WriteToConsole(); //outputs 'whpizzapshell pizzah'
    //std::cout << (demo3 == "whpizzapshell pizzah") << std::endl; //outputs 1 (true)
    //std::cout << (demo3 != "whpizzapshell pizzah") << std::endl; //outputs 0 (false)
    //demo = "Hello, Steve!";
    //std::cout << demo[5] << std::endl; //outputs ','
    //std::cout << (demo < "gandhi") << std::endl; //outputs 0 (false)
    //std::cout << (demo < "igandhi") << std::endl; //outputs 1 (true)
    //demo.Replace(", Steve", "").WriteToConsole(); //outputs 'Hello!'
    //(demo + " " + demo3).WriteToConsole(); //outputs 'Hello! whpizzapshell pizzah'
    //demo += " I am world.";
    //demo.WriteToConsole(); //outputs 'Hello! I am world."
    //String input;
    //input.ReadFromConsole(); //takes user input from console
    //std::cout << (input == "Bob") << std::endl; //returns 1 (true) if user input was 'Bob' otherwise returns false
    //input.Prepend("Hello ").WriteToConsole(); //outputs 'Hello {input}'
    //demo3.ReadFromConsole(); //waits for input

    String test = "Hello, this is a test.";

    struct check {
        bool condition;
        const char* text;
    };
    
    check checks[] = { 
        {test.Length() == 22, "Length"},
        {test.CharacterAt(5) == ',', "CharacterAt"},
        {test.EqualTo("Hello, this is a test."), "EqualTo"},
        {test.Append("123").EqualTo("Hello, this is a test.123"), "Append"},
        {test.Prepend("abc").EqualTo("abcHello, this is a test.123"), "Prepend"},
        {test.CStr() == &test.CharacterAt(0), "CStr"},
        {test.ToLower().EqualTo("abchello, this is a test.123"), "ToLower"},
        {test.ToUpper().EqualTo("ABCHELLO, THIS IS A TEST.123"), "ToUpper"},
        {test.Find("IS") == 12 && test.Find(13, "IS") == 15, "Find"},
        {test.Replace("IS", "bob").EqualTo("ABCHELLO, THbob bob A TEST.123"), "Replace"}
    };

    std::time_t result = std::time(nullptr);
    std::tm tm = *std::localtime(&result);
    std::cout << "Date: " << tm.tm_mday << "/" << tm.tm_mon << "/" << tm.tm_year + 1900;
    std::cout << " Time: " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec;
    std::cout << std::endl;

    for (int i = 0; i < sizeof(checks) / sizeof(check); i++) {    
        std::cout << "Test " << i << " " << checks[i].text << " method ";

        if (checks[i].condition) {
            std::cout << "successful" << std::endl;
        }
        else {
            std::cout << "failed" << std::endl;
        }
    }
}
