#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct student
{
	string name;
	string sex;
	string id;
	int grade;
	student(string name,string sex,string id,int grade):name(name),sex(sex),id(id),grade(grade){}
	void print()
	{
		cout<<name<<" "<<id<<endl;
	}
};

vector<student> boy;
vector<student> girl;

bool cmp(const student &a,const student &b)
{
	return a.grade<b.grade;
}

int main()
{
	int i,j,n;
	string name,sex,id;
	int grade;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>name>>sex>>id>>grade;
		if(sex=="F")
		{
			girl.push_back(student(name,sex,id,grade));
		}else
		{
			boy.push_back(student(name,sex,id,grade));
		}
	}

	bool flag=false;
	if(!girl.empty())
	{
		sort(girl.begin(),girl.end(),cmp);
		girl[girl.size()-1].print();
	}else
	{
		flag=true;
		cout<<"Absent"<<endl;
	}
	if(!boy.empty())
	{
		sort(boy.begin(),boy.end(),cmp);
		boy[0].print();
	}else
	{
		flag=true;
		cout<<"Absent"<<endl;
	}
	if(flag) cout<<"NA"<<endl;
	else
	{
		cout<<girl[girl.size()-1].grade-boy[0].grade<<endl;
	}
	return 0;
}
