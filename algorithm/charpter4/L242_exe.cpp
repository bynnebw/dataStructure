#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
    	if( s.length() != t.length() ) return false;

    	map<char,int> record1;
    	for( int i = 0; i < s.length(); i ++ )
    		record1[s[i]] ++;

    	map<char,int> record2;
    	for( int i = 0; i < t.length(); i ++ )
    		record2[t[i]] ++;

    	if( record1.size() == record2.size() )
    	{
    		for( int i = 0; i < record1.size(); i ++ )
    		{
    			if( record1[i] != record2[i] )
    				return false;
    		}
    		return true;
    	}

    	return false;
    }
};

int main(int argc, char const *argv[])
{
	string s = "anagram",t = "nagaram";
	Solution().isAnagram(s,t);
	return 0;
}