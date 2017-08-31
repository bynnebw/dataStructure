#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) 
    {
    	unordered_map<char,int> freq;
    	vector<string> bucket(s.size()+1,"");
    	string res;

    	for( int i = 0; i < s.size(); i ++ )
    		freq[s[i]] ++;

    	
    }
};

int main(int argc, char const *argv[])
{
	string s = "tree";
	cout<<Solution().frequencySort(s)<<endl;
	return 0;
}