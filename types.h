#pragma once
typedef unsigned char byte;
typedef char sbyte;
typedef wchar_t wchar;
typedef long long int64;
#define null 0
#ifdef UNICODE
typedef wchar achar;
#else
typedef char achar;
#endif // !UNICODE
#ifdef UNICODE
#define _T(x) L ## x 
#else
#define _T(x)  x 
#define T(x) _T(x)
#endif 
