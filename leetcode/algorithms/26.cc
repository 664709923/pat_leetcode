#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int i,j = 0;
        int same;
    	for(i = 1; i < nums.size(); i++ ) {
            if(nums[i] > nums[j]) {
                nums[++j] = nums[i];
            }
    	}
        return j+1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v(10,2);
	int size = s.removeElement(v);
	cout << "lens:" << size <<endl;
	for(int i = 0; i < size; i++) {
		cout << v[i] << endl;
	}

	return 0;
}