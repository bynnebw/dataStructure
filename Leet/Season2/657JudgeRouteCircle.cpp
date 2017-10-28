#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
		int v = 0, h = 0;

		for( char ch:moves ){
			switch(ch){
				case 'U': v++; break;
				case 'D': v--; break;
				case 'L': h++; break;
				case 'R': h--; break;
			}
		}

		return v == 0 && h == 0;
    }
};


int main(int argc, char const *argv[])
{
	string moves = {'U','D','L','R'};

	bool res = Solution().judgeCircle(moves);

	cout<<res<<endl;

	return 0;
}