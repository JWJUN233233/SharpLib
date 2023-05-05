#include "String.h"

SharpLib::AString::AString()
{
	_value = new Array<char>();
}

SharpLib::AString::AString(AString& string)
{
	int strLen = Stdlib::StrLenA(string);
	Array<char>* arrayTmp = new Array<char>(strLen + 1);
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp->operator[](i) = string[i];
	}
	_value = arrayTmp;
}

SharpLib::AString::AString(char* string)
{
	int strLen = Stdlib::StrLenA(string);
	Array<char>* arrayTmp = new Array<char>(strLen + 1);
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp->operator[](i) = string[i];
	}
	_value = arrayTmp;
}
SharpLib::AString::AString(char const* string)
{
	int strLen = Stdlib::StrLenA((char*)string);
	Array<char>* arrayTmp = new Array<char>(strLen + 1);
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp->operator[](i) = string[i];
	}
	_value = arrayTmp;
}

SharpLib::AString::AString(Array<char> string)
{
	_value = new Array<char>(string);
}

SharpLib::AString::~AString()
{
	delete _value;
}

SharpLib::AString::operator char* ()
{
	return _value->operator char *();
}


bool SharpLib::AString::operator==(AString string)
{
	return Stdlib::StrEqualToA(_value->operator char *(), string);
}

bool SharpLib::AString::operator==(char* string)
{
	return Stdlib::StrEqualToA(_value->operator char *(), string);
}

SharpLib::AString SharpLib::AString::operator+(AString string)
{
	int newSize = Stdlib::StrLenA(_value->operator char *()) + Stdlib::StrLenA(string) + 1;
	char* tmp = new char [newSize];
	Stdlib::StrLinkA(tmp, _value->operator char *(), string);
	Array<char> arrayTmp(newSize);
	for (int i = 0;i < newSize;i++) {
		arrayTmp[i] = tmp[i];
	}
	delete[] tmp;
	return AString(arrayTmp);
}

void SharpLib::AString::operator+=(AString string)
{
	Array<char> tmp = ((*this) + string);
	delete _value;
	_value = new Array<char>(tmp);
}

void SharpLib::AString::operator+=(char* string)
{
	Array<char> tmp = ((*this) + string);
	delete _value;
	_value = new Array<char>(tmp);
}

SharpLib::AString::operator Array<char>()
{
	Array<char> arrayTmp(_value->GetLength());
	for (int i = 0; i < _value->GetLength(); i++)
	{
		arrayTmp[i] = _value->At(i);
	}
	return arrayTmp;
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

int SharpLib::Stdlib::StrLenW(wchar_t* str)
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

bool SharpLib::Stdlib::StrEqualToW(wchar_t* left, wchar_t* right)
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

void SharpLib::Stdlib::StrLinkW(wchar_t* newStr, wchar_t* left, wchar_t* right)
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

wchar_t* SharpLib::Stdlib::StrCopyW(wchar_t* str)
{
	int strLen = Stdlib::StrLenW(str);
	wchar_t* arrayTmp = new wchar_t[strLen + 1];
	for (int i = 0; i < strLen + 1; i++)
	{
		arrayTmp[i] = str[i];
	}
	return arrayTmp;
}
