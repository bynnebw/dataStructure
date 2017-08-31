/*
Description of the code:

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/


//这是修正过的代码版本,使用语言库给我们提供的一个非常便利的方式

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
    	set<int> record( nums1.begin(),nums1.end() );
    	
    	//只希望每个元素只记录一次
    	set<int> resultSet;
    	for( int i = 0; i < nums2.size(); i ++ )
    		if( record.find(nums2[i]) != record.end() )
    			resultSet.insert( nums2[i] );

    	return vector<int>(resultSet.begin(),resultSet.end());
    }


};

int main(int argc, char const *argv[])
{
	vector<int> vector1 = {1,2,2,1};
	vector<int> vector2 = {2,2};
	Solution().intersection(vector1,vector2);
	return 0;
}