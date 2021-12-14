#pragma once

#include <exception>
#include "Ienumerable.h"
#include "Array.h"

class String : public Ienumerable<char> {

public:

	String()
	{

	}

	String(const char* str) {
		*this = str;
	}

	String& operator = (const char* str) {

	
		Size = 0;
		while (str[Size++] != '\0');
		Size -= 1;

		delete[] this->str;
		this->str = new char[Size];

		//std::cout << Size;

		for (int i = 0; i < Size; i++)
		{
			this->str[i] = str[i];
		}

		return *this;
	};

	String(Ienumerable<char>& source)
	{

		this->Size = source.GetSize();

		if (source.GetSize() > 0) {

			str = new char[Size];

			for (int i = 0; i < source.GetSize(); i++)
				str[i] = source[i];

		}
	}

	String(const String& source) : String((Ienumerable<char>&)source) {}


	int GetSize() {
		return Size;
	}

	void Resize(int new_size) {
		delete[] str;
		str = new char[new_size];
		Size = new_size;
	}


	void PushFront(char elem) {
		Insert(elem, 0);
	};

	void PushBack(char elem) {
		char* temp = new char[Size];

		std::memcpy(temp, str, Size * sizeof(char));

		delete[] str;
		str = new char[Size + 1];

		std::memcpy(str, temp, Size * sizeof(char));

		str[Size] = elem;

		delete[] temp;

		Size += 1;
	};

	void Insert(char elem, int index) {

		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {

			char* temp = new char[Size];

			std::memcpy(temp, str, Size * sizeof(char));

			delete[] str;
			str = new char[Size + 1];

			for (int i = 0; i < Size + 1; i++)
				str[i] = (i == index ? elem : temp[i - (i > index)]);

			delete[] temp;

			Size += 1;

		}
	};


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
		else
		{

			char* temp = new char[Size];

			std::memcpy(temp, str, Size * sizeof(char));

			delete[] str;
			str = new char[Size - 1];

			for (int i = 0; i < Size - 1; i++)
				str[i] = temp[i + (i >= index)];

			Size -= 1;

		}
	};


	char& operator[] (const int index) {
		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else
		{
			return str[index];
		};
	}

	char At(const int index) {
		return this->operator[](index);
	}


	String& operator += (String& rhs) {

		String temp(*this);

		this->Resize(this->GetSize() + rhs.GetSize() - 1);

		for (int i = 0; i < temp.GetSize(); i++)
		{
			this->operator[](i) = temp[i];
		}

		for (int i = 0; i < rhs.GetSize(); i++)
		{
			this->operator[](temp.GetSize() + i - 1) = rhs[i];
		}

		return *this;
	}

	String& operator += (const char* rhs) {

		String temp(rhs);

		this->operator+=(temp);

		return *this;
	}

	~String()
	{
		delete[] str;
	}

private:

	int Size;

	char* str = NULL;

};

//class String : Array<char> {
//
//public:
//
//	String()
//	{
//
//	}
//
//	String(const char* str) {
//		*this = str;
//	}
//
//	String& operator = (const char* str) {
//
//		int Size = 0;
//		while (str[Size++] != '\0');
//
//		this->Resize(Size);
//
//		for (int i = 0; i < Size; i++)
//			((Ienumerable<char>*)this)->operator[](i) = str[i];
//
//		return *this;
//	}
//
//private:
//
//
//};