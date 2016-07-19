#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
    	char tmp;
        int i, j;
        i = 0;
        j = s.length() - 1;
        while(i < j) {
        	tmp = s[i];
        	s[i] = s[j];
        	s[j] = tmp;
        	i++;
        	j--;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string str = "hello world";
    cout<<s.reverseString(str)<<endl;
}