//思路：对这个数字的每个数位求平方和，如果和为1或者平方和是之前出现过的就不进行求和，
//根据最后的结果判断是不是一个开心的数字。

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {
    	int num = 0;
    	unordered_map<int,bool> table;
    	table[n] = 1;
    	while( n != 1 )
    	{
    		while( n )
    		{
    			num += (n%10) * (n%10);
    			n/=10;
    		}
    		if(table[num]) break;
    		else table[num] = 1;
    		n = num; num = 0;
    	}
    	return 1 == n;
    }
};

int main(int argc, char const *argv[])
{
	Solution().isHappy(19);
	return 0;
}