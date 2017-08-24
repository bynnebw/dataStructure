#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<string> findWords(std::vector<string>& words)
    {
        std::vector<string> res;
        for(auto str : words)
        {
            bool r1 = str.find_first_of("QWERTYUIOPqwertyuiop") == string::npos ? false : true;
            bool r2 = str.find_first_of("ASDFGHJKLasdfghjkl") == string::npos ? false : true;
            bool r3 = str.find_first_of("ZXCVBNMzxcvbnm") == string::npos ? false : true;

            if(r1 + r2 + r3 == 1)
            {
                res.push_back(str);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{

	vector<string> v = {"Hello","Alaska","Dad","Peace"};

    Solution s;

    std::vector<string> m = s.findWords(v);

    for(int i = 0;i < m.size();i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;    

	return 0;
}