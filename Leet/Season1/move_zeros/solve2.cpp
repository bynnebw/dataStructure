#include <iostream>
#include <vector>

using namespace std;

//leetcode第283道题目，move zeros。


//时间复杂度O(n)
//空间复杂度O(1),原地进行整个操作
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for( int i = 0; i < nums.size(); i ++ )
        	if( nums[i] )
        		swap(nums[k++],nums[i]);
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