#pragma once
#include <exception>

template<typename T>
class Linked_List {

public:

	Linked_List()
	{
		
	}

	bool Is_Empty() {
		return Head == NULL;
	}

	void Push_Back(T value) {

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

	void Push_Front(T value) {
		Size += 1;
		Head = new Node(value, Head);
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

	int Get_Size() {
		return Size;
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