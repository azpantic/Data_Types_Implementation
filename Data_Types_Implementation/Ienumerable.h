#pragma once

template<typename T>
class Ienumerable {

public:

	virtual int GetSize() = 0;


	virtual void PushFront(T elem) = 0;

	virtual void PushBack(T elem) = 0;

	virtual void Insert(T elem, int index) = 0;


	virtual void RemoveFirst() = 0;

	virtual void RemoveLast() = 0;

	virtual void Remove(int index) = 0;


	virtual T& operator[](const int index) = 0;

	virtual T At(const int index) = 0;

};

