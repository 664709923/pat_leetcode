#include<vector>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int > result;
        map<int,int> tempMap;
        for(int i = 0; i < nums.size(); i++)
        {
            tempMap[nums[i]]=-1;
            tempMap[target - nums[i]]=-1;
        }
        for(int i =0;i< nums.size();i++){
            int other = target - nums[i];

            if(tempMap[other] != -1){
                result.push_back(tempMap[other]);
                result.push_back(i);
                return result;
            }
            else{
                tempMap[nums[i]]=i;
            }
        }
        return result;
    }
};



int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(0);
    vector<int> res = s.twoSum(nums, 0);

    for(int i = 0; i < res.size(); i++)
    {
        printf("%d\n", res[i]);
    }

}
