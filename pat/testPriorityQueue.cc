#include<queue>
#include<iostream>
using namespace std;

struct cmp{
	bool operator() (int a,int b){
		return a<b;
	}
};

int main(){
	priority_queue<int,vector<int>,cmp> q;
	int n=10;
	while(n--){
		q.push(n);
	}
	cout<<q.top();
	return 0;
}
