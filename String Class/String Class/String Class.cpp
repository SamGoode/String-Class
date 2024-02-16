#include <iostream>
//#include "String.h"

class String {
    public:
        char* data;
        int length;

        String();

        String(const char* text) {
            length = 0;
            for (int i = 0;*(text + i) != NULL; i++) {
                length++;
            }

            data = new char[length + 1];
            for (int i = 0; i < length; i++) {
                *(data + i) = *(text + i);
            }
            *(data + length) = NULL;
        }

        ~String() {
            delete[] data;
        }

        void append(String& text) {
            int oldLength = length;
            char* oldData = data;
            
            length += text.length;
            data = new char[length + 1];

            for (int i = 0; i < oldLength; i++) {
                *(data + i) = *(oldData + i);
            }
            for (int i = oldLength; i < length; i++) {
                *(data + i) = *(text.data - oldLength + i);
            }
            *(data + length) = NULL;

            delete[] oldData;
        }
};

int main() {
    String test = String("munkhzul");
    String buddies = String(" and ");
    String test2 = String("jevan");
    test.append(buddies);
    test.append(test2);
    std::cout << test.data << std::endl;
    std::cout << test.length << std::endl;

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
