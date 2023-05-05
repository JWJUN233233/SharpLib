#pragma once
#include "ICollection.h"
namespace SharpLib::Collection {

	template <typename T>
	class Enumerator{
	public:
		Enumerator(ICollection<T>* value);
		Enumerator(Enumerator<T>& value);
		T MoveNext();
		T This();
		bool HasNext();
		void Reset();
		Enumerator<T> begin();
		Enumerator<T> end();
		bool operator !=(Enumerator& that);
		Enumerator<T>& operator++();
		T& operator*();
	private:
		ICollection<T>* _value;
		int _postion;
	};
	template <typename T>
	class IEnumerable{
	public:
		virtual Enumerator<T> GetEnumerator() = 0;
		operator Enumerator<T>();
	};
	template<typename T>
	inline IEnumerable<T>::operator Enumerator<T>()
	{
		return GetEnumerator();
	}
	template<typename T>
	inline Enumerator<T>::Enumerator(ICollection<T>* value)
	{
		_value = value;
		_postion = 0;
	}
	template<typename T>
	inline Enumerator<T>::Enumerator(Enumerator<T>& value)
	{
		_value = value._value;
		_postion = value._postion;
	}
	template<typename T>
	inline T Enumerator<T>::MoveNext()
	{
		T toRerurn = This();
		_postion++;
		return toRerurn;
	}
	template<typename T>
	inline T Enumerator<T>::This()
	{
		return _value->Get(_postion);
	}
	template<typename T>
	inline bool Enumerator<T>::HasNext()
	{
		return _postion <= _value->Size();
	}
	template<typename T>
	inline void Enumerator<T>::Reset()
	{
		_postion = 0;
	}
	template<typename T>
	inline Enumerator<T> Enumerator<T>::begin()
	{
		return *this;
	}
	template<typename T>
	inline Enumerator<T> Enumerator<T>::end()
	{
		Enumerator<T> toReturn(_value);
		toReturn._postion = _value->Size();
		return toReturn;
	}
	template<typename T>
	inline bool Enumerator<T>::operator!=(Enumerator& that)
	{
		return _value != that._value || _postion != that._postion;
	}
	template<typename T>
	inline Enumerator<T>& Enumerator<T>::operator++()
	{
		_postion++;
		return *this;
	}
	template<typename T>
	inline T& Enumerator<T>::operator*()
	{
		return _value->operator[](_postion);
	}
}