#include <iostream>

using namespace std;

//basically build the structure of the bianry search tree.

template<typename Key,typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node( Key key, Value value )
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node* root; //树需有有一个根节点。
	int count;

public:
	BST()
	{
		root = NULL;
		count = 0;
	}
	~BST()
	{
		//TO DO : ~BST()
	}

	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}
	void insert(Key key,Value value)
	{
		root = insert(root,key,value);
	}
private:
	Node* insert(Node* node,Key key,Value value)
	{
		if( node == NULL )
		{
			count++;
			return new Node(key,value);
		}

		if( key == node->key )
			node->value = value;
		else if( key < node->key )
			node->left = insert(node->left,key,value);
		else // key > node->right
			node->right = insert(node->right,key,value);

		return node;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}