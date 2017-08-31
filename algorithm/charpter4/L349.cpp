/*
Description of the code:

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
    	set<int> record;
    	for( int i = 0; i < nums1.size(); i ++ )
    		record.insert( nums1[i] );

    	//只希望每个元素只记录一次
    	set<int> resultSet;
    	for( int i = 0; i < nums2.size(); i ++ )
    		if( record.find(nums2[i]) != record.end() )
    			resultSet.insert( nums2[i] );

    	vector<int> resultVector;
    	//遍历容器类需要使用容器的迭代器
    	for( set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter ++ )
    		resultVector.push_back( *iter );  //迭代器中的这个iter其实是一个指针，因为push_back的内容是具体元素的数值，所以要取元素值

    	return resultVector;
    }


};

int main(int argc, char const *argv[])
{
	vector<int> vector1 = {1,2,2,1};
	vector<int> vector2 = {2,2};
	Solution().intersection(vector1,vector2);
	return 0;
}