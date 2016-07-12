#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j = 0;
    	for(i = 0; i < nums.size(); i++ ) {
    		if(nums[i] == val) {
    			continue;
    		}else{
    			nums[j++] = nums[i];
    		}
    	}
        return j;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v(10,2);
	int size = s.removeElement(v,2);
	cout << "lens:" << size <<endl;
	for(int i = 0; i < size; i++) {
		cout << v[i] << endl;
	}

	return 0;
}