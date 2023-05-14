#include "String.h"

SharpLib::AString::AString()
{
	_value = new char[0];
}

SharpLib::AString::AString(AString& string)
{
	_value = Stdlib::StrCopyA(string);
}

SharpLib::AString::AString(char* string)
{
	_value = Stdlib::StrCopyA(string);
}
SharpLib::AString::AString(char const* string)
{
	_value = Stdlib::StrCopyA((char*)string);
}

SharpLib::AString::~AString()
{
	delete _value;
}

bool SharpLib::AString::operator==(AString string)
{
	return Stdlib::StrEqualToA(_value, string);
}

bool SharpLib::AString::operator==(char* string)
{
	return Stdlib::StrEqualToA(_value, string);
}

SharpLib::AString SharpLib::AString::operator+(AString string)
{
	int newSize = Stdlib::StrLenA(_value) + Stdlib::StrLenA(string) + 1;
	char* tmp = new char [newSize];
	Stdlib::StrLinkA(tmp, _value, string);
	AString tstr = tmp;
	delete[] tmp;
	return tstr;
}

void SharpLib::AString::operator+=(AString string)
{
	delete[] _value;
	_value = ((*this) + string);
}

void SharpLib::AString::operator+=(char* string)
{
	delete[] _value;
	_value = ((*this) + string);
}

SharpLib::AString::operator char*()
{
	return _value;
}
SharpLib::WString::WString()
{
	_value = new wchar[0];
}

SharpLib::WString::WString(WString& string)
{
	_value = Stdlib::StrCopyW(string);
}

SharpLib::WString::WString(wchar* string)
{
	_value = Stdlib::StrCopyW(string);
}
SharpLib::WString::WString(wchar const* string)
{
	_value = Stdlib::StrCopyW((wchar*)string);
}
SharpLib::WString::~WString()
{
	delete _value;
}

SharpLib::WString::operator wchar* ()
{
	return _value;
}


bool SharpLib::WString::operator==(WString string)
{
	return Stdlib::StrEqualToW(_value, string);
}

bool SharpLib::WString::operator==(wchar* string)
{
	return Stdlib::StrEqualToW(_value, string);
}

SharpLib::WString SharpLib::WString::operator+(WString string)
{
	int newSize = Stdlib::StrLenW(_value) + Stdlib::StrLenW(string) + 1;
	wchar* tmp = new wchar[newSize];
	Stdlib::StrLinkW(tmp, _value, string);
	WString tstr = tmp;
	delete[] tmp;
	return tstr;
}

void SharpLib::WString::operator+=(WString string)
{
	delete[] _value;
	_value = ((*this) + string);
}

void SharpLib::WString::operator+=(wchar* string)
{
	delete[] _value;
	_value = ((*this) + string);
}

int SharpLib::Stdlib::StrLenA(char* str) {
	int i = 0;
	int len = 0;
	while (true) {
		if (str[i] == '\0') {
			break;
		}
		len++;
		i++;
	}
	return len;
}

bool SharpLib::Stdlib::StrEqualToA(char* left, char* right)
{
	if (StrLenA(left) == StrLenA(right)) {
		for (int i = 0;i < StrLenA(left);i++) {
			if (left[i] != right[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void SharpLib::Stdlib::StrLinkA(char* newStr, char* left, char* right)
{
	int n = 0;
	for (int i = 0;i < StrLenA(left);i++) {
		if (left[i] != '\0') {
			newStr[n] = left[i];
			n++;
		}
	}
	for (int i = 0;i < StrLenA(right);i++) {
		if (right[i] != '\0') {
			newStr[n] = right[i];
			n++;
		}
	}
	newStr[n] = '\0';
}

char* SharpLib::Stdlib::StrCopyA(char* str)
{
	int strLen = Stdlib::StrLenA(str);
	char* arrayTmp = new char[strLen + 1];
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp[i] = str[i];
	}
	return arrayTmp;
}

int SharpLib::Stdlib::StrLenW(wchar* str)
{
	int i = 0;
	int len = 0;
	while (true) {
		if (str[i] == L'\0') {
			break;
		}
		len++;
		i++;
	}
	return len;
}

bool SharpLib::Stdlib::StrEqualToW(wchar* left, wchar* right)
{
	if (StrLenW(left) == StrLenW(right)) {
		for (int i = 0;i < StrLenW(left);i++) {
			if (left[i] != right[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void SharpLib::Stdlib::StrLinkW(wchar* newStr, wchar* left, wchar* right)
{
	int n = 0;
	for (int i = 0;i < StrLenW(left);i++) {
		if (left[i] != L'\0') {
			newStr[n] = left[i];
			n++;
		}
	}
	for (int i = 0;i < StrLenW(right);i++) {
		if (right[i] != L'\0') {
			newStr[n] = right[i];
			n++;
		}
	}
	newStr[n] = L'\0';
}

wchar* SharpLib::Stdlib::StrCopyW(wchar* str)
{
	int strLen = Stdlib::StrLenW(str);
	wchar* arrayTmp = new wchar[strLen + 1];
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp[i] = str[i];
	}
	return arrayTmp;
}
