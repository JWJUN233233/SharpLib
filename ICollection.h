#pragma once
namespace SharpLib::Collection {
	template <typename T>
	class ICollection
	{
	public:
		T At(int index);
		T First();
		T End();
		virtual T Get(int index) = 0;
		virtual void Set(T value, int index) = 0;
		virtual int Size() = 0;
		virtual T& operator[](int index) = 0;
		virtual const T& operator[](int index) const = 0;
	};
	template<typename T>
	inline T ICollection<T>::At(int index)
	{
		return Get(index);
	}
	template<typename T>
	inline T ICollection<T>::First()
	{
		return Get(0);
	}
	template<typename T>
	inline T ICollection<T>::End()
	{
		return Get(Size() - 1);
	}
}