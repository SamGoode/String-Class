#include "String.h"

String::String() {

}

String::String(const char* _str) {
	length = sizeof(_str);

	for (int i = 0; i < length; i++) {
		data[i] = _str[i];
	}
}

String::String(const String& _other) {
	
}

String::~String()
{
}

size_t String::Length() const
{
	return size_t();
}
