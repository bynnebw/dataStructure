//2017.09.05晚统计人数的程序


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class d
{
public:
    unordered_map<int,int> counting(vector<int>& nums){

        unordered_map<int,int> res;

        for( vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter ++ )
        	res[*iter] ++;

        return res;
    }

};

int main(int argc, char const *argv[])
{
	vector<int> record;
	unordered_map<int,int> res;
	int n;
	while( cin>>n ){
		record.push_back(n);
	}
	cout<<endl;

	res = d().counting(record);

	cout<<"The total times each numbers have appeared: "<<endl;

	for( unordered_map<int,int>::iterator iter = res.begin(); iter != res.end(); iter ++ )
		cout<<iter->first<<" : "<<iter->second<<endl;

	cout<<endl;

	return 0;
}