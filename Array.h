#pragma once
#include <corecrt_malloc.h>
#include "ICollection.h"
#include "Enumerator.h"
#include <cstdarg>
namespace SharpLib::Collection{
	template <typename T>
	int GetCArrayLength(T* CArray);
	template <typename T>
	T* CopyCArray(T* CArray);
	template <typename T>
	inline void SetCArrayLength(T** CArray, int length);
	template <typename T> class Array : public ICollection<T>, public IEnumerable<T>
	{
	public:
		explicit Array(int len = 0);
		Array(T value ...);
		Array(Array<T>& Array);
		~Array();
		Enumerator<T> GetEnumerator();
		T Get(int index);
	    void Set(T value, int index);
		int Size();
		int GetLength();
		void SetLength(int length);
		long GetLongLength();
		T* ToCArray();
		T& operator[](int i);
		const T& operator[](int i) const;
		void operator = (Array<T> value);
		operator T* ();
	private:
		T* _value;
	};
	template <typename T>
	inline int GetCArrayLength(T* CArray) {
		int size = _msize((void*)CArray);
		return size / sizeof(T);
	}

	template <typename T>
	inline T* CopyCArray(T* CArray) {
		int arraylen = GetCArrayLength(CArray);
		T* tmp = new T[arraylen];
		for (int i = 0;i < arraylen;i++) {
			tmp[i] = CArray[i];
		}
		return tmp;
	}

	template <typename T>
	inline void SetCArrayLength(T** CArray, int length) {
		int CopyLen = 0;
		T* tmp = new T[length];
		T* Array = *CArray;
		if (GetCArrayLength<T>(Array) < length) {
			CopyLen = GetCArrayLength<T>(Array);
		}
		else {
			CopyLen = length;
		}
		for (int i = 0; i < CopyLen; i++) {
			tmp[i] = Array[i];
		}
		delete[] Array;
		*CArray = tmp;
	}
	template<typename T>
	inline Array<T>::Array(int len)
	{
		_value = new T[len];
	}
	template<typename T>
	inline Array<T>::Array(T value ...)
	{
		va_list arg_ptr;
		va_start(arg_ptr, value);
		_value = new T[value];
		for (int i = 0; i < value; i++)
		{
			operator[](i) = va_arg(arg_ptr, T);
		}
		va_end(arg_ptr);
	}
	template<typename T>
	inline Array<T>::Array(Array<T>& Array)
	{
		_value = CopyCArray<T>(Array);
	}
	template<typename T>
	inline Array<T>::~Array()
	{
		delete[] _value;
	}
	template<typename T>
	inline Enumerator<T> Array<T>::GetEnumerator()
	{
		return Enumerator<T>(this);
	}
	template<typename T>
	inline T Array<T>::Get(int index)
	{
		return operator[](index);
	}
	template<typename T>
	inline void Array<T>::Set(T value, int index)
	{
		operator[](index) = value;
	}
	template<typename T>
	inline int Array<T>::Size()
	{
		return GetLength();
	}
	template<typename T>
	inline int Array<T>::GetLength()
	{
		return GetCArrayLength<T>(_value);
	}
	template<typename T>
	inline void Array<T>::SetLength(int length)
	{
		SetCArrayLength<T>(&_value, length);
	}
	template<typename T>
	inline long Array<T>::GetLongLength()
	{
		return (long)GetLength();
	}

	template<typename T>
	inline T* Array<T>::ToCArray()
	{
		return _value;
	}
	template<typename T>
	inline T& Array<T>::operator[](int i)
	{
		return _value[i];
	}
	template<typename T>
	inline const T& Array<T>::operator[](int i) const
	{
		return _value[i];
	}

	template<typename T>
	inline void Array<T>::operator=(Array<T> value)
	{
		_value = CopyCArray<T>(value);
	}

	template<typename T>
	inline Array<T>::operator T* ()
	{
		return _value;
	}

}