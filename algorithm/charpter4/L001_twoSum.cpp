#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
    	unordered_map<int,int> record;
    	for( int i = 0; i < nums.size(); i ++ )
    	{
    		int complement = target - nums[i];
    		if( record.find(complement) != record.end() )  //如果可以找到
    		{
    			int res[2] = {i,record[complement]};
    			return vector<int>(res,res+2);
    		}
    		record[nums[i]] = i;
    	}
    	throw invalid_argument("The input has no solution");
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {2,7,11,15};
	int target = 9;
	Solution().twoSum(nums,target);
	return 0;
}