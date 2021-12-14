#include "Linked_Lists.h"

template<typename Tkey, typename Tvalue>
class Map {
public:

	
	Tvalue& operator[] (Tkey key) {

		for (int i = 0; i < Nodes.GetSize(); i++)
			if (key = Nodes[i].GetKey())
				return Nodes[i].GetValue();

		Nodes.PushBack(Node(key));

		return Nodes[Nodes.GetSize() - 1].GetValue();

	}

	void Clear() {
		Nodes.Clear();
	}

	int GetKeyCount() {
		return Nodes.GetSize();
	}

	void Remove(Tkey key) {
		
		for (int i = 0; i < Nodes.GetSize(); i++)
			if (key = Nodes[i].GetKey()) {
				Nodes.Remove(i);
				return;
			}
	}	

	bool FindKey(Tkey key) {
		for (int i = 0; i < Nodes.GetSize(); i++)
			if (key = Nodes[i].GetKey())
				return true;

		return false;
	}

private:

	class Node {
	public:

		Node() {};

		Node(Tkey key, Tvalue value = Tvalue())  {
			this->key = key;
			this->value = value;
		};

		Tkey GetKey() {
			return key;
		}

		Tvalue& GetValue() {
			return value;
		}

	private:

		Tkey key;

		Tvalue value;

	};

	Linked_List<Node> Nodes;
};