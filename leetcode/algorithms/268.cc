#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0,b=0, i;
        for(i = 0; i <= nums.size(); i++) {
        	a ^= i;
        }
        for(auto n : nums) {
        	b ^= n;
        }
        return a ^ b;
    }
};
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	cout<<s.missingNumber(v)<<endl;
}
