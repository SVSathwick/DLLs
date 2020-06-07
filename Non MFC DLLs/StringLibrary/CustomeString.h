#pragma once

#ifdef STRINGLIBRARY_EXPORTS
#define STRINGLIBRARY_API __declspec(dllexport)
#else
#define STRINGLIBRARY_API __declspec(dllimport)
#endif

class CustomString
{
private:
    char* cstr;
public:
    STRINGLIBRARY_API CustomString();
    STRINGLIBRARY_API CustomString(char* str);
    STRINGLIBRARY_API CustomString(const CustomString& str);
    STRINGLIBRARY_API ~CustomString();

    STRINGLIBRARY_API operator char* ();
    STRINGLIBRARY_API operator const char* ();
    STRINGLIBRARY_API CustomString operator+(const CustomString& q)const;
    STRINGLIBRARY_API CustomString& operator=(const CustomString& q);
};