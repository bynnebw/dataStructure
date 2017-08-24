#include <iostream>
#include <vector>

using namespace std;

//leetcode第283道题目，move zeros。


//时间复杂度O(n)
//空间复杂度O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tempArray;
        for( int i = 0; i < nums.size(); i ++ )
        	if( nums[i] )
        		tempArray.push_back( nums[i] );

        for( int i = 0; i < tempArray.size(); i ++ )
        	nums[i] = tempArray[i];

        for( int i = tempArray.size(); i < nums.size(); i ++ )
        	nums[i] = 0;
    }
};


int main(int argc, char const *argv[])
{
	vector<int> nums = {0,1,0,3,12};
	Solution().moveZeroes(nums);
	for( int i = 0; i < nums.size(); i ++ )
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}