#include <iostream>
#include <vector>
#include <string>
#include "SequenceST.h"
#include "FileOps.h"

//remaining two header files.

using namespace std;

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
	bool contain(Key key)
	{
		return contain(root,key);
	}
	Value* search(Key key)
	{
		return search(root,key);
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

	bool contain(Node* node,Key key)
	{
		if( node == NULL )		//递归到底的情况，树的根节点为空的时候，直接返回false.
			return	false;

		if( key == node->key )
			return true;
		else if( key < node->key )
			return contain( node->left, key );
		else   //key > node->key
			return contain( node->right, key );
	}

	Value* search(Node* node , Key key)
	{
		if( node == NULL )
			return NULL;

		if( key == node->key )
			return &(node->value);
		else if( key < node->key )
			return search( node->left, key );
		else 
			return search( node->right,key );
	}
};

int main(int argc, char const *argv[])
{
	string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;

        cout << endl;


        // test BST
        time_t startTime = clock();
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        cout << "'god' : " << *bst.search("god") << endl;
        time_t endTime = clock();
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

        cout << endl;


        // test SST
        startTime = clock();
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        cout << "'god' : " << *sst.search("god") << endl;

        endTime = clock();
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    }

    return 0;
}