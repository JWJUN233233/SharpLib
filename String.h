#pragma once
#include "types.h"
namespace SharpLib {
	class AString;
	class WString;
#ifdef UNICODE
	typedef WString String;
#else
	typedef AString String;
#endif
	namespace Stdlib {
		int StrLenA(char* str);
		bool StrEqualToA(char* left, char* right);
		void StrLinkA(char* newStr, char* left, char* right);
		char* StrCopyA(char* str);
		int StrLenW(wchar* str);
		bool StrEqualToW(wchar* left, wchar* right);
		void StrLinkW(wchar* newStr, wchar* left, wchar* right);
		wchar* StrCopyW(wchar* str);
	}
	class AString
	{
	public:
		AString();
		AString(AString& string);
		AString(char* string);
		AString(char const* string);
		~AString();
		operator char* ();
		bool operator ==(AString string);
		bool operator ==(char* string);
		AString operator +(AString string);
		void operator+=(AString string);
		void operator+=(char* string);
	private:
		char* _value;
	};
	class WString
	{
	public:
		WString();
		WString(WString& string);
		WString(wchar* string);
		WString(wchar const* string);
		~WString();
		operator wchar* ();
		bool operator ==(WString string);
		bool operator ==(wchar* string);
		WString operator +(WString string);
		void operator+=(WString string);
		void operator+=(wchar* string);
	private:
		wchar* _value;
	};
}

