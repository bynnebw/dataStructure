//word pattern
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
    	map<char,int> p2i;
    	map<string,int> w2i;
    	
    	//if I just include the header file which is the sstream file and I can use the istringstream character
    	
    	istringstream in(str);
    	int i = 0, n = pattern.size();
    	for( string word; in >> word; ++ i )
    	{
    		if( i == n || p2i[pattern[i]] != w2i[word] )
    			return false;
    		p2i[pattern[i]] = w2i[word] = i + 1;
    	}

    	return i == n;

    }
};

int main(int argc, char const *argv[])
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	Solution().wordPattern(pattern,str);
	return 0;
}