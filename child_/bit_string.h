#include "../parent_/string.h"
#include "fstream"
class BitString : public String
{
public:
	BitString() : String() {}
	BitString(const char* s) : String(s) {}
	BitString(const BitString& s) : String(s) {}
	BitString& operator=(const BitString& s)
	{
		if (this != &s)
		{
			delete[] str;
			len = s.len;
			str = new char[len + 1];
			strcpy(str, s.str);
		}
		return *this;
	}
	~BitString() {}
	BitString operator-()
	{
		BitString temp(*this);
		for (int i = 0; i < len; i++)
			if (temp.str[i] == '0')
				temp.str[i] = '1';
			else
				temp.str[i] = '0';
		for (int i = len - 1; i >= 0; i--)
			if (temp.str[i] == '0')
			{
				temp.str[i] = '1';
				break;
			}
			else
				temp.str[i] = '0';
		return temp;
	}
	BitString operator+(const BitString& s)
	{
		BitString temp;
		temp.len = len + s.len;
		temp.str = new char[temp.len + 1];
		strcpy(temp.str, str);
		strcat(temp.str, s.str);
		return temp;
	}
	BitString& operator+=(const BitString& s)
	{
		len += s.len;
		char* temp = new char[len + 1];
		strcpy(temp, str);
		strcat(temp, s.str);
		delete[] str;
		str = temp;
		return *this;
	}
	bool operator==(const BitString& s)
	{
		return strcmp(str, s.str) == 0;
	}
	bool operator!=(const BitString& s)
	{
		return strcmp(str, s.str) != 0;
	}
	bool check(const char* s)
	{
		for (int i = 0; i < strlen(s); i++)
			if (s[i] != '0' && s[i] != '1')
				return false;
		return true;
	}
	friend ostream& operator<<(ostream& os, const BitString& bs)
	{
		os << bs.str;
		return os;
	}
};