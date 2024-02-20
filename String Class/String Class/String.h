#pragma once

class String {
	private:
		char null;
		char* dataPtr;
		int length;

	public:
		String();

		String(const char* textPtr);

		String(const String& str);

		~String();

		size_t Length() const;
		char& CharacterAt(size_t index);
		const char& CharacterAt(size_t index) const;

		bool EqualTo(const String& str) const;

		String& Append(const String& str);
		String& Prepend(const String& str);

		const char* CStr() const;

		String& ToLower();
		String& ToUpper();

		size_t Find(const String& str);
		size_t Find(size_t startIndex, const String& str);

		String& Replace(const String& find, const String& replace);

		String& ReadFromConsole();
		String& WriteToConsole();

		bool operator==(const String& _other);
		bool operator!=(const String& _other);

		String& operator=(const String& _str);

		char& operator[](size_t _index);
		const char& operator[](size_t _index) const;
};
