#include "String.h"

String::String() {

}

String::String(const char* textPtr) {
    length = 0;
    for (int i = 0;*(textPtr + i) != 0; i++) {
        length++;
    }

    dataPtr = new char[length + 1];
    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = *(textPtr + i);
    }
    *(dataPtr + length) = 0;
}

String::String(const String& string) {
    length = string.Length();
    dataPtr = new char[length + 1];
    for (int i = 0; i < length; i++) {
        *(dataPtr + i) = *(string.CStr() + i);
    }
    *(dataPtr + length) = 0;
}

String::~String() {
    delete[] dataPtr;
}

size_t String::Length() const {
	return length;
}

/*
char& String::CharacterAt(size_t index) {
    if (index < 0 || index > length) {
        return '0';
    }

    return *(dataPtr + index);
}

const char& String::CharacterAt(size_t _index) const {
    // TODO: insert return statement here
}
*/

const char* String::CStr() const {
	return dataPtr;
}
