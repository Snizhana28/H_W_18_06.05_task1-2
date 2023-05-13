#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#ifndef string_class
#define string_class

using namespace std;

class String 
{
protected:
	int len;
	char *str;
public:
	// constructors
	String()
	{
		this->str = new char[1];
		this->str[0] = '\0';
	}
	String(const char* str)
	{
		int len = strlen(str);
		this->str = new char[len + 1];
		for (int i = 0; i < len; i++) {
			this->str[i] = str[i];
		}
		this->str[len] = '\0';
	}
	// copy constructor
	String(const String& other)
	{
		len = other.len;
		str = new char[len + 1];
		strcpy(str, other.str);
	}
	// assignment operator=
	String& operator=(const String& other)
	{
		if (this != &other) {
			delete[] str;
			len = other.len;
			str = new char[len + 1];
			strcpy(str, other.str);
		}
		return *this;
	}
	// method to get the string length
	int GetLenght() const
	{
		return len;
	}
	// string cleanup method (make string empty)
	void clear()
	{
		delete[] str;
		str = new char[1];
		str[0] = '\0';
	}
	// destructor
	~String()
	{
		len = 0;
		delete[] str;
	}
	//Arithmetic Operators : +
	String operator+ (const String& other) const 
	{
		String temp;
		temp.len = len + other.len;
		temp.str = new char[temp.len + 1];
		strcpy(temp.str, str);
		strcat(temp.str, other.str);
		return temp;
	}
	//Assignment Operators: +=
	String& operator+=(const String& other)
	{
		len += other.len;
		char* temp = new char[len + 1];
		strcpy(temp, str);
		strcat(temp, other.str);
		delete[] str;
		str = temp;
		return *this;
	}
	//check for equality (==)
	bool operator==(const String& other)
	{
		return strcmp(str, other.str) == 0;
	}
	//check for inequality (!=)
	bool operator!=(const String& other)
	{
		return strcmp(str, other.str) != 0;
	}
};

#endif
