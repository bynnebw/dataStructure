#include <iostream>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap
{
private:
	Item* data;
	int count;
public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity+1];
		count = 0;
	}
	
	~MaxHeap()
	{
		delete[] data;
	}
	
	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}
	
};


int main(int argc, char const *argv[])
{
	MaxHeap<int> maxheap = MaxHeap<int>(10);
	cout<<maxheap.size()<<endl;

	return 0;
}