#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//这种解法感觉像是交叉绑定

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
    	unordered_map<char,char> hash,reflect;
    	for( int i = 0; i < s.length(); ++ i )
    	{
    		if( hash.find(s[i]) == end(hash) && reflect.find(t[i]) == end(reflect))
    		{
    			hash[s[i]] = t[i];
    			reflect[t[i]] = s[i];
    		}
    		else
    		{
    			if( hash[s[i]] != t[i] )
    				return false;
    		}
    	}

    	return true;
    }
};

int main(int argc, char const *argv[])
{
	string s = "egg",t = "add";
	Solution().isIsomorphic(s,t);
	return 0;
}