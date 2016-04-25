#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> ivec;
	string val;
	while(cin>>val)
	{
		ivec.push_back(val);
	}
	for(vector<string>::size_type ix=0;ix!=ivec.end()-ivec.begin();ix++)
	{
		cout<<ivec[ix]<<endl;
	}
	return 0;
}
