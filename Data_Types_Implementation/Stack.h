#pragma once
#include <exception>

template<class T>
class Stack {

public:

	bool Is_Empty() {
		return (Last == NULL);
	}

	void Push(T value) {
		Last = new Node(value, Last);
	}

	T Peek() {

		if (Last == NULL)
			throw std::exception("Stack is empty");
		else
			return Last->Get_Value();
	}

	void Pop() {

		if (Last == NULL)
			throw std::exception("Stack is empty");
		else {
			Node* temp = Last->Get_Prev();
			delete Last;
			Last = temp;
		}
	}

private:

	class Node {

	public:

		Node(T value, Node* Prev)
		{
			this->value = value;
			this->Prev = Prev;
		}

		Node* Get_Prev() {
			return Prev;
		}

		T Get_Value() {
			return value;
		}

	private:

		Node* Prev = NULL;

		T value;
	};

	Node* Last;

};