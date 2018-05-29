#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String
{
private:
	size_t length;
	char *str;

public:
	String();
	String(const char *c);
	String(const String& t);
	~String();

	String& operator= (const String& t);
	String operator+ (const String& t) const;
	char& operator[] (size_t i);

	void get_input(std::istream& in);
	size_t get_length() const;

	friend std::ostream& operator<< (std::ostream& out, const String& t);
	friend std::istream& operator>> (std::istream& in, String& t);
};

String::String()
{
	length = 0;
	str = NULL;
}
String::String(const char *c)
{
	length = strlen(c) + 1;
	str = new char[length];
	strcpy_s(str, length, c);
	str[length - 1] = '\0';
}
String::String(const String& t)
{
	length = strlen(t.str) + 1;
	str = new char[length];
	strcpy_s(str, length, t.str);
	str[length - 1] = '\0';
}
String::~String()
{
	if (str != NULL)
	{
		delete[] str;
	}
}


String& String::operator= (const String& t)
{
	length = strlen(t.str) + 1;
	str = new char[length];
	strcpy_s(str, length, t.str);
	str[length - 1] = '\0';

	return *this;
}

String String::operator+ (const String& t) const
{
	char* newStr = new char[strlen(str) + strlen(t.str) + 1];
	strcpy_s(newStr, strlen(str) + 1, str);
	strcat_s(newStr, strlen(str) + strlen(t.str) + 1, t.str);
	newStr[strlen(str) + strlen(t.str)] = '\0';

	String returnObj(newStr);
	delete[] newStr;

	return returnObj;
}

char& String::operator[] (size_t i)
{
	return str[i];
}
void String::get_input(std::istream& in)
{
	while (true)
	{
		char c = in.get();

		if (c == '\n')
		{
			break;
		}

		if (length == 0)
		{
			length = 2;
		}
		else
		{
			++length;
		}

		char* newStr = new char[length];
		if (str != NULL)
		{
			strcpy_s(newStr, strlen(str) + 1, str);
		}
		newStr[length - 2] = c;
		newStr[length - 1] = '\0';

		delete[] str;

		str = newStr;
	}
}
size_t String::get_length() const
{
	if (length == 0)
	{
		return 0;
	}
	else
	{
		return (length - 1);
	}
}
std::ostream& operator<< (std::ostream& out, const String& t)
{
	out << t.str;
	return out;
}

std::istream& operator>> (std::istream& in, String& t)
{
	t.get_input(in);
	return in;
}