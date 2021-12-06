#pragma once
#include <exception>
#include <iostream>
#include "Ienumerable.h"

template<typename T>
class Linked_List : public Ienumerable<T> {

public:

	Linked_List()
	{

	}

	Linked_List(std::initializer_list<T> source) {

		this->Size = source.size();

		this->Head = new Node(*source.begin());
		Node* temp = Head;

		for (auto i = source.begin() + 1; i != source.end(); i++)
			temp = temp->Add_New(*i);

	}

	Linked_List(Ienumerable<T>& source)
	{

		if (source.GetSize() > 0) {

			this->Size = source.GetSize();

			this->Head = new Node(source[0]);
			Node* temp = Head;

			for (int i = 1; i < source.GetSize(); i++)
				temp = temp->Add_New(source[i]);


		}
	}

	Linked_List(int Size, T default_value = default(T)) {
		
		Size = Size;

		Head = new Node(default_value);
		Node* temp = Head;

		for (int i = 1; i < Size; i++)
			temp = temp->Add_New(default_value);
		
	}


	Linked_List(const Linked_List<T>& source) : Linked_List((Ienumerable<T>&)source) {};

	bool Is_Empty() {
		return Head == NULL;
	}

	int GetSize() {
		return Size;
	}


	void PushFront(T value) {
		Size += 1;
		Head = new Node(value, Head);
	}

	void PushBack(T value) {

		Size += 1;
		if (Is_Empty())
		{
			Head = new Node(value);
		}
		else
		{
			Node* Last = Head;

			while (!Last->Is_Last())
				Last = Last->Get_Next();

			Last->Add_New(value);
		}
	}

	void Insert(T value, int index) {
		
		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {
			Size += 1;

			Node* place_to_insert = Head;

			for (int i = 0; i < index - 1; i++)
				place_to_insert = place_to_insert->Get_Next();

			Node* temp = new Node(value, place_to_insert->Get_Next());

			place_to_insert->Set_Next(temp);
		}
	}


	void RemoveFirst() {

		if (Is_Empty()) {
			throw std::exception("List is empty");
		}
		else {

			Size -= 1;

			Node* temp = Head->Get_Next();

			delete Head;
			Head = temp;
		}

	}

	void RemoveLast() {

		if (Is_Empty()) {
			throw std::exception("List is empty");
		}
		else {

			Size -= 1;

			Node* Last = Head;

			for (int i = 0; i < Size - 1; i++)
				Last = Last->Get_Next();

			delete Last->Get_Next();

			if (Size == 0)
				Head = NULL;
			else
				Last->Set_Next(NULL);
		}

	}

	void Remove(int index) {

		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {
			Size -= 1;

			Node* place_to_delete = Head;

			for (int i = 0; i < index - 1; i++)
				place_to_delete = place_to_delete->Get_Next();

			if (index == 0) {
				Head = Head->Get_Next();
				delete place_to_delete;
			}
			else
			{

				Node* temp = place_to_delete->Get_Next();

				place_to_delete->Set_Next(temp->Get_Next());

				delete temp;
			}
		}
	}


	T& operator[](const int index) {

		if (index < 0 || index >= Size) {
			throw std::exception("Index out of range");
		}
		else {
			Node* temp = Head;

			for (int i = 0; i < index; i++)
				temp = temp->Get_Next();

			return temp->Get_Value();
		}

	}

	T At(const int index) {
		return this->operator[](index);
	}

	
	void Clear() {

		Node* temp = Head;

		while (!temp->Is_Last()) {
			temp = Head->Get_Next();
			delete[] Head;
			Head = temp;
		}

		Head = NULL;

		Size = 0;

	}

private:

	int Size = 0;

	class Node {

	public:

		Node(T value)
		{
			this->value = value;
		}

		Node(T value, Node* Next) : Node(value)
		{
			this->Next = Next;
		}

		T& Get_Value() {
			return value;
		}

		bool Is_Last()
		{
			return Next == NULL;
		}

		// return pointer to new last Node
		Node* Add_New(T value) {
			Node* temp = new Node(value);
			this->Next = temp;
			return temp;
		}

		void Set_Next(Node* Next) {
			this->Next = Next;
		}

		Node* Get_Next() {
			return Next;
		}

	private:

		Node* Next = NULL;

		T value;

	};

	Node* Head = NULL;

};