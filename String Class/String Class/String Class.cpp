#include <iostream>
#include "String.h"

int main() {
    String test = "Sebastian";
    String buddies = " and ";
    String test2 = test;
    buddies.Prepend(test);
    buddies.Append(test2);

    int finds = 0;
    String find = "an";

    for (int i = 0; buddies.Find(i, find) != -1; i += buddies.Find(i, find) + 1) {
        finds++;
    }
    std::cout << finds << std::endl;

    buddies.WriteToConsole();
    buddies.Replace("bastian", "ven");
    buddies.WriteToConsole();
    //std::cout << buddies.CharacterAt(0);
    //std::cout << (test != "Sebastia");
    test += "bop";
    (test + "beep").WriteToConsole();
    std::cout << test[11];
    //buddies += "womp";
    buddies.ReadFromConsole();
    buddies.WriteToConsole();

    /*
    char dummy;
    std::cin.get(dummy);
    std::cin.putback(dummy);
    
    int bufferSize;

    bufferSize = std::cin.rdbuf()->in_avail();

    char* text = new char[bufferSize];

    for (int i = 0; i < bufferSize; i++) {
        std::cin.get(*(text + i));
    }
    //*(text + bufferSize - 1) = NULL;
    
    std::cout << text;

    */
    /*
    char* text = new char[0];
    std::cin >> text;

    int length = 0;
    for (int i = 0; *(text + i) != NULL; i++) {
        length++;
    }

    char* text2 = new char[length];

    for (int i = 0; i < length; i++) {
        *(text2 + i) = *(text + i);
    }

    std::cout << text << std::endl;
    std::cout << length << std::endl;
    */

    std::cout << buddies.Find("om") << std::endl;
}
