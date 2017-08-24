#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class solution
{
public:

	int distributeCandies(vector<int>& candies)
	{
		size_t kinds = 0;
		sort(candies.begin(), candies.end());
		for( int i = 0; i < candies.size(); i ++ )
		{
			kinds += candies[i] != candies[i-1]; //居然可以这样写？
		}
		cout<<min(kinds,candies.size()/2)<<endl;	//why in this place is using the min function?
		return min(kinds,candies.size()/2);
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v = {0,0,0,4};
	solution s1;
	s1.distributeCandies(v);
	return 0;
}