#include<vector>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>

using namespace std;

class Number{
public:
    int num;
    int index;
};

bool cmp(const Number &a, const Number &b){
    return a.num < b.num;
}



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Number> m;
        m.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            Number n;
            n.index = i;
            n.num = nums[i];
            m.push_back(n);
        }

        sort(m.begin(), m.end(), cmp);
        vector<int> result;
        int i = 0, j = m.size() - 1;
        while(i < j)
        {
            if(m[i].num + m[j].num == target)
            {
                result.push_back(m[i].index);
                result.push_back(m[j].index);
                return result;
            }else if(nums[i] + nums[j] > target)
            {
                j--;
            }else
            {
                i++;
            }
        }



        return result;
    }
};



int main()
{
    Solution s;
    vector<int> nums(10, 2);
    vector<int> res = s.twoSum(nums, 4);

    for(int i = 0; i < res.size(); i++)
    {
        printf("%d\n", res[i]);
    }

}
