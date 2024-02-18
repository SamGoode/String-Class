#include <iostream>
#include "String.h"

/*
class String {
    public:
        char* dataPtr;
        int length;

        String();

        String(const char* text) {
            length = 0;
            for (int i = 0;*(text + i) != 0; i++) {
                length++;
            }

            dataPtr = new char[length + 1];
            for (int i = 0; i < length; i++) {
                *(dataPtr + i) = *(text + i);
            }
            *(dataPtr + length) = 0;
        }

        ~String() {
            delete[] dataPtr;
        }

        void append(String& text) {
            int oldLength = length;
            char* oldData = dataPtr;
            
            length += text.length;
            dataPtr = new char[length + 1];

            for (int i = 0; i < oldLength; i++) {
                *(dataPtr + i) = *(oldData + i);
            }
            for (int i = oldLength; i < length; i++) {
                *(dataPtr + i) = *(text.dataPtr - oldLength + i);
            }
            *(dataPtr + length) = NULL;

            delete[] oldData;
        }
};
*/

int main() {
    String test = String("sebastian");
    String buddies = String(" and ");
    String test2 = String(test);
    //test.append(buddies);
    //test.append(test2);
    std::cout << test.CStr() << std::endl;
    std::cout << test.Length() << std::endl;
    std::cout << buddies.CStr() << std::endl;
    std::cout << buddies.Length() << std::endl;
    std::cout << test2.CStr() << std::endl;
    std::cout << test2.Length() << std::endl;

    /*
    char* data;
    int length;

    const char* a = "munkhzulandducks";

    length = 0;
    for (int i = 0;*(a + i) != NULL; i++) {
        length++;
    }
    length++;
    
    data = new char[length];
    
    for (int i = 0; i < length; i++) {
        *(data + i) = *(a + i);
    }
    
    std::cout << data << std::endl;
    delete[] data;
    std::cout << (*(a + 16) == NULL) << std::endl;
    std::cout << length << std::endl;
    //std::cout << typeid(data).name() << std::endl;
    */
}
