#include <iostream>
#include <string>

using namespace std;

class solution
{
private:
	string s;
public:
	solution(string s)
	{
		this->s = s;
	}
	~solution()
	{

	}

	string reverseWords(string s)
	{
		int i = 0, j = 0;
		while( j < s.length() )
		{
			while( j < s.length() && s[j] != ' ' ) j ++;
			int k = j - 1;
			while( i < k) swap( s[i++] ,s[k--]); 
			i =  ++j;	//what's happening here???????????
		}
		return s;
	}
	
};


int main(int argc, char const *argv[])
{
	string s = "Let\'s take LeetCode contest";
	cout<<s<<endl;
	solution s1(s);
	cout<<s1.reverseWords(s)<<endl;
	return 0;
}