//3sum 我的解法，但是这种解法会把所有的结果都罗列出来，会出现重复的情况
//后续应该会删除掉重复的元素

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> record;
        vector<vector<int>> res;

        for( int i = 0; i < nums.size(); i ++ )
            record[nums[i]] ++;

        for( int i = 0; i < nums.size(); i ++ ){
            for( int j = i+1; j < nums.size(); j ++ ){
                if( record.find(0-nums[i]-nums[j]) != record.end() && record[0-nums[i]-nums[j]]){
                    vector<int> temp = {nums[i],nums[j],(-nums[i]-nums[j])};
                    record[0-nums[i]-nums[j]] --;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution().threeSum(nums);
    return 0;
}