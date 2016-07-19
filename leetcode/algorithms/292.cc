#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        bool ret[4] = {false,true,true,true};
        return ret[n%4];
    }
};

int main()
{
    Solution s;
    cout<<s.canWinNim(4)<<endl;
}