#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n;

struct student
{
	student(){}
	student(string name,string id,int grade): name(name),id(id),grade(grade){}
	string name;
	string id;
	int grade;
};

bool cmp(const student& s1,const student& s2)
{
	return s1.grade>s2.grade;
}

int main()
{
	string name,id;
	int grade;
	int i;
	cin>>n;
	student s[n];
	for(i=0;i<n;i++)
	{
		cin>>name>>id>>grade;
		s[i]=student(name,id,grade);
	}
	sort(s,s+n,cmp);
	int low,high;
	cin>>low>>high;
	bool flag=true;
	for(i=0;i<n;i++)
	{
		if(s[i].grade>=low&&s[i].grade<=high)
		{
			flag=false;
			cout<<s[i].name<<" "<<s[i].id<<endl;
		}
	}
	if(flag) cout<<"NONE"<<endl;
	return 0;
}
