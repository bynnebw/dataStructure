/*

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
    	map<int,int> record;
    	for( int i = 0; i < nums1.size(); i ++ )
    		record[nums1[i]] ++;

    	std::vector<int> resultVector;
    	for( int i = 0; i < nums2.size(); i ++ )
    	{
    		if( record[nums2[i]] > 0 )
    		{
    			resultVector.push_back(nums2[i]);
    			record[nums2[i]] --;
    		}
    	}
    			
    	return resultVector;

    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums1 = {1,2,2,1};
	vector<int> nums2 = {2,2};
	Solution().intersect(nums1,nums2);
	return 0;
}