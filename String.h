#pragma once

#include "Array.h"
using SharpLib::Collection::Array;
namespace SharpLib {
	class AString;
	typedef AString String;
	namespace Stdlib {
		int StrLenA(char* str);
		bool StrEqualToA(char* left, char* right);
		void StrLinkA(char* newStr, char* left, char* right);
		char* StrCopyA(char* str);
		int StrLenW(wchar_t* str);
		bool StrEqualToW(wchar_t* left, wchar_t* right);
		void StrLinkW(wchar_t* newStr, wchar_t* left, wchar_t* right);
		wchar_t* StrCopyW(wchar_t* str);
	}
	class AString
	{
	public:
		AString();
		AString(AString& string);
		AString(char* string);
		AString(char const* string);
		AString(Array<char> string);
		~AString();
		operator char* ();
		operator Array<char>();
		bool operator ==(AString string);
		bool operator ==(char* string);
		AString operator +(AString string);
		void operator+=(AString string);
		void operator+=(char* string);
	private:
		Array<char>* _value;
	};
}

