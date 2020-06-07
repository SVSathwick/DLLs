
#include "pch.h"
#include "CustomeString.h"

CustomString::CustomString()
{
	cstr = 0;
}
CustomString::CustomString(char* str)
{
	size_t length = strlen(str) + 1;
	cstr = new char[length];
	strcpy_s(cstr, length, str);
}
CustomString::CustomString(const CustomString& str)
{
	if (this == &str)
		return;
	size_t length = strlen(str.cstr) + 1;
	cstr = new char[length + 1];
	strcpy_s(cstr, length, str.cstr);
}
CustomString::~CustomString()
{
	if (cstr)
		delete[] cstr;
}
CustomString::operator char* ()
{
	return cstr;
}
CustomString::operator const char* ()
{
	return cstr;
}
CustomString CustomString::operator +(const CustomString& q) const
{
	CustomString s;
	size_t newLength = strlen(cstr) + strlen(q.cstr) + 1;
	s.cstr = new char[newLength];
	strcpy_s(s.cstr, newLength, cstr);
	strcat_s(s.cstr, newLength, q.cstr);
	return s;
}
CustomString& CustomString::operator =(const CustomString& q)
{
	if (this != &q)
	{
		if (cstr)
			delete[] cstr;
		cstr = new char[strlen(q.cstr) + 1];
		strcpy_s(cstr, strlen(q.cstr) + 1, q.cstr);
	}
	return *this;
}