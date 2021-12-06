#pragma once
#include <exception>
#include "Ienumerable.h"

template<typename T>
class Array : public Ienumerable<T> {

public:

	Array()
	{

	}

	Array(std::initializer_list<T> source) {

		this->Size = source.size();

		Pointer = new T[Size];

		for (auto i = source.begin(); i != source.end(); i++)
			Pointer[i - source.begin()] = *i;

	}

	Array(Ienumerable<T>& source)
	{

		if (source.GetSize() > 0) {

			this->Size = source.GetSize();

			Pointer = new T[Size];

			for (int i = 0; i < source.GetSize(); i++)
				Pointer[i] = source[i];

		}
	}

	Array(Array<T>& source) : Array((Ienumerable<T>&)source) {};

	Array(int Size, T default_value = default(T)) {

		Pointer = new T[Size];

		for (int i = 0; i < Size; i++)
		{
			Pointer[i] = default_value;
		}
	}


	int GetSize() {
		return Size;
	}




	void PushFront(T elem) {
		Insert(elem, 0);
	};

	void PushBack(T elem) {
		T* temp = new T[Size];

		std::memcpy(temp, Pointer, Size * sizeof(T));

		delete[] Pointer;
		Pointer = new T[Size + 1];

		std::memcpy(Pointer, temp, Size * sizeof(T));

		Pointer[Size ] = elem;

		delete[] temp;

		Size += 1;
	};

	void Insert(T elem, int index) {

		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {

			T* temp = new T[Size];

			std::memcpy(temp, Pointer, Size * sizeof(T));

			delete[] Pointer;
			Pointer = new T[Size + 1];

			for (int i = 0; i < Size + 1; i++)
				Pointer[i] = (i == index ? elem : temp[i - (i > index)]);

			delete[] temp;

			Size += 1;

		}

	}


	void RemoveFirst() {
		Remove(0);
	};

	void RemoveLast() {
		Remove(Size);
	};

	void Remove(int index) {
		if (index < 0 || index > Size) {
			throw std::exception("Index out of range");
		}
		else {


			T* temp = new T[Size];

			std::memcpy(temp , Pointer , Size * sizeof(T));

			delete Pointer;
			Pointer = new T[Size - 1];

			for (int i = 0; i < Size - 1; i++)
				Pointer[i] = temp[i + (i >= index)];



			Size -= 1;

		}
	}


	T& operator[](const int index) {
		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {
			return Pointer[index];
		};
	};

	T At(const int index) {
		return this->operator[](index);
	};


	void Clear() {

		delete[] Pointer;
		Size = 0;
	}

private:

	int Size = 0;

	T* Pointer = NULL;

};
