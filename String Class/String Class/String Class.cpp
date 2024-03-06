#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include "String.h"

int main() {
    struct check {
        bool condition;
        const char* text;
    };
    
    String test = "Hello, this is a test.";
    String test2 = "";

    check checks[] = {
        {test.Length() == 22 && test2.Length() == 0, "Length"},
        {test.CharacterAt(5) == ',' && test2.CharacterAt(0) == NULL, "CharacterAt"},
        {test.EqualTo("Hello, this is a test.") && test2.EqualTo(""), "EqualTo"},
        {test.Append("123").EqualTo("Hello, this is a test.123") && test2.Append("123").EqualTo("123"), "Append"},
        {test.Prepend("abc").EqualTo("abcHello, this is a test.123") && test2.Prepend("abc").EqualTo("abc123"), "Prepend"},
        {test.CStr() == &test.CharacterAt(0) && test2.CStr() == &test2.CharacterAt(0), "CStr"},
        {test.ToLower().EqualTo("abchello, this is a test.123") && test2.ToLower().EqualTo("abc123"), "ToLower"},
        {test.ToUpper().EqualTo("ABCHELLO, THIS IS A TEST.123") && test2.ToUpper().EqualTo("ABC123"), "ToUpper"},
        {test.Find("IS") == 12 && test.Find(13, "IS") == 15 && test2.Find("") == -1, "Find"},
        {test.Replace("IS", "bob").EqualTo("ABCHELLO, THbob bob A TEST.123") && test2.Replace("ABC123", "").EqualTo(""), "Replace"}
    };

    std::ofstream logs;
    logs.open("logs.txt", std::ios::app);

    time_t result = time(nullptr);
    tm tm = *localtime(&result);
    logs << "Date: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900;
    logs << " Time: " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec;
    logs << std::endl;

    int successes = 0;
    for (int i = 0; i < sizeof(checks) / sizeof(check); i++) {
        logs << "Test " << i + 1 << " " << checks[i].text << " method ";

        if (checks[i].condition) {
            logs << "successful" << std::endl;
            successes++;
        }
        else {
            logs << "failed" << std::endl;
        }
    }

    logs << successes << "/" << sizeof(checks) / sizeof(check) << " tests successful";

    for (int i = 0; i < 2; i++) {
        logs << std::endl;
    }

    logs.close();
}
