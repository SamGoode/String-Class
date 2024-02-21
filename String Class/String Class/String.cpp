#include "String.h"
#include <iostream>

String::String() {
    dataPtr = new char[1];
    *dataPtr = 0;
    length = 0;
}

String::String(const char* textPtr) {
    length = 0;
    for (int i = 0; *(textPtr + i) != 0; i++) {
        length++;
    }

    dataPtr = new char[length + 1];
    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = *(textPtr + i);
    }
    *(dataPtr + length) = 0;
}

String::String(const String& str) {
    length = str.Length();
    dataPtr = new char[length + 1];
    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = *(str.CStr() + i);
    }
    *(dataPtr + length) = 0;
}

String::~String() {
    delete[] dataPtr;
}

size_t String::Length() const {
	return length;
}

char& String::CharacterAt(size_t index) {
    if (index > length) {
        return *(dataPtr + length); //returns null terminator
    }

    return *(dataPtr + index);
}

const char& String::CharacterAt(size_t index) const {
    if (index > length) {
        return *(dataPtr + length); //returns null terminator
    }

    return *(dataPtr + index);
}

bool String::EqualTo(const String& str) const {
    if (length != str.Length()) {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (*(dataPtr + i) != *(str.CStr() + i)) {
            return false;
        }
    }

    return true;
}

String& String::Append(const String& str) {
    char* oldPtr = dataPtr;
    dataPtr = new char[length + str.Length() + 1];

    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = *(oldPtr + i);
    }
    
    for (int i = 0; i < str.Length(); i++) {
        *(dataPtr + length + i) = *(str.CStr() + i);
    }

    length += str.Length();
    *(dataPtr + length) = 0;
    delete[] oldPtr;
    return *this;
}

String& String::Prepend(const String& str) {
    char* oldPtr = dataPtr;
    dataPtr = new char[length + str.Length() + 1];

    for (int i = 0; i < str.Length(); i++) {
        *(dataPtr + i) = *(str.CStr() + i);
    }
    
    for (int i = 0; i < length; i++) {
        *(dataPtr + str.Length() + i) = *(oldPtr + i);
    }

    length += str.Length();
    *(dataPtr + length) = 0;
    delete[] oldPtr;
    return *this;
}

const char* String::CStr() const {
    return dataPtr;
}

String& String::ToLower() {
    for (int i = 0; i < length; i++) {
        if (*(dataPtr + i) >= 65 && *(dataPtr + i) <= 90) {
            *(dataPtr + i) += 32;
        }
    }

    return *this;
}

String& String::ToUpper() {
    for (int i = 0; i < length; i++) {
        if (*(dataPtr + i) >= 97 && *(dataPtr + i) <= 122) {
            *(dataPtr + i) -= 32;
        }
    }

    return *this;
}

size_t String::Find(const String& str) {
    if (length < str.Length()) {
        return -1;
    }

    for (int i = 0; i < length; i++) {
        if (length - i < str.Length()) {
            break;
        }
        /*
        if (*(dataPtr + i) != *str.CStr()) {
            continue;
        }

        if (str.Length() == 1) {
            return i;
        }
        */
        for (int j = 0; j < str.Length(); j++) {
            if (*(dataPtr + i + j) != *(str.CStr() + j)) {
                break;
            }

            if (j == str.Length() - 1) {
                return i;
            }
        }
    }

    return -1;
}

size_t String::Find(size_t startIndex, const String& str) {
    if (length - startIndex < str.Length()) {
        return -1;
    }

    for (int i = startIndex; i < length; i++) {
        if (length - i < str.Length()) {
            break;
        }
        /*
        if (*(dataPtr + i) != *str.CStr()) {
            continue;
        }

        if (str.Length() == 1) {
            return i;
        }
        */
        for (int j = 0; j < str.Length(); j++) {
            if (*(dataPtr + i + j) != *(str.CStr() + j)) {
                break;
            }

            if (j == str.Length() - 1) {
                return i;
            }
        }
    }

    return -1;
}

//There's probably a better way to do this
String& String::Replace(const String& find, const String& replace) {
    String oldStr = *this;
    
    delete[] dataPtr;
    dataPtr = new char[0];
    length = 0;

    for (int i = 0; i < oldStr.Length(); i++) {
        if (i == oldStr.Find(i, find)) {
            Append(replace);
            i += find.Length() - 1;
        }
        else {
            char* temp = new char[2];
            *temp = oldStr.CharacterAt(i);
            *(temp + 1) = 0;
            Append(temp);
            delete[] temp;
        }
    }

    return *this;
}

String& String::ReadFromConsole() {
    char dummyChar;
    std::cin.get(dummyChar);
    std::cin.putback(dummyChar);
    int bufferSize = std::cin.rdbuf()->in_avail();

    delete[] dataPtr;
    dataPtr = new char[bufferSize];
    for (int i = 0; i < bufferSize - 1; i++) {
        std::cin.get(*(dataPtr + i));
    }
    *(dataPtr + bufferSize - 1) = 0;

    return *this;
}

String& String::WriteToConsole() {
    std::cout << dataPtr << std::endl;

    return *this;
}

bool String::operator==(const String& str) {
    return EqualTo(str);
}

bool String::operator!=(const String& str) {
    return !EqualTo(str);
}

String& String::operator=(const String& str) {
    delete[] dataPtr;
    length = str.Length();

    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = str.CharacterAt(i);
    }
    *(dataPtr + length) = 0;

    return *this;
}

char& String::operator[](size_t index) {
    return CharacterAt(index);
}

const char& String::operator[](size_t index) const {
    return CharacterAt(index);
}
/*
bool String::operator<(const String& str) {

}
*/

String String::operator+(const String& str) {
    String newStr = *this;
    newStr.Append(str);
    return newStr;
}

String& String::operator+=(const String& str) {
    Append(str);
    return *this;
}