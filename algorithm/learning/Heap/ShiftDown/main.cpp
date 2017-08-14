#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap
{
private:
	Item* data;
	int count;
	int capacity;

	void shiftup(int k)
	{
		while( k > 1 && data[k/2] < data[k] )
		{
			swap( data[k/2] , data[k] );
			k /= 2;
		}	
	}
	
	void shiftdown(int k)
	{

		while( 2*k <= count )	//之前这里没有加等于号，导致执行结果中，倒数第二个数总是喜欢和倒数第一个数颠倒位置
		{
			int j = 2*k;

			if( j+1 <= count && data[j] < data[j+1] )		//这是存在右节点的情况
					j ++;

			if( data[k] >= data[j] )	break;		//这里就是通用的了，针对存在左节点，右节点均适用
				swap( data[k] , data[j] );		
				k = j;
		}
	}

public:
	
	MaxHeap(int capacity)
	{
		data = new Item[capacity+1];
		count = 0;
		this->capacity = capacity;
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

	void insert(Item item)
	{
		assert( count + 1 <= capacity );	//保证数组不越界

		data[count+1] = item;
		shiftup(count+1);
		count ++;
	}
/*
	Item extractMax()
	{
		while( count > 1)
		{
			int a = data[1];
			swap( data[1] , data[count] );
			count --;

			shiftdown(1);
			return a;	
		}
		
	}
*/

	Item extractMax()
	{
		assert( count > 0 );
		Item ret = data[1];

		swap( data[1] , data[count] );
		count --;
		shiftdown(1);
		return ret;
	}

};


int main(int argc, char const *argv[])
{
	MaxHeap<int> maxheap = MaxHeap<int>(30);
	srand(time(NULL));
	for( int i = 0; i < 15; i ++ )
	{
		maxheap.insert( rand()%100 );
	}

	while( !maxheap.isEmpty() )
	{
		cout<<maxheap.extractMax()<<" ";
	}
	cout<<endl;

	return 0;
}