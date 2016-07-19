#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		long long int aa = a;
		long long int bb = b;
		long long int i;
		if(b>0) {
			for(i = 0; i < bb; i++){
				aa++;
			}
		}else{
			bb = -bb;
			for(i = 0; i < bb; i++){
				aa--;
			}
		}
		return aa;
	}
};

int main()
{
	Solution s;
	cout<<s.getSum(2147483647,-2147483648)<<endl;
}
