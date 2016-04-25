#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

bool replace_password(string& password) {
    bool isChanged = false;
    for (int i=0; i<password.size(); i++) {
        char replace = NULL;
        switch (password[i]) {
            case '1':replace = '@';break;
            case '0':replace = '%';break;
            case 'l':replace = 'L';break;
            case 'O':replace = 'o';break;
        }
        if (replace != NULL) {
            password[i] = replace;
            isChanged = true;
        }
    }
    return isChanged;
}


bool isModify(string& s)
{
	bool flag=false;

	while(s.find('1')!=string::npos)
	{
		flag=true;
		s[s.find('1')]='@';
	}

	while(s.find('0')!=string::npos)
	{
		flag=true;
		s[s.find('0')]='%';
	}

	while(s.find('l')!=string::npos)
	{
		flag=true;
		s[s.find('l')]='L';
	}

	while(s.find('O')!=string::npos)
	{
		flag=true;
		s[s.find('O')]='o';
	}

	return flag;
}

int ans[1000];
int main()
{
	int i,n,count=0;
	cin>>n;
	string s[n][2];
	for(i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		if(isModify(s[i][1]))
		{
			ans[count++]=i;
		}
	}

	if(count==0)
	{
		if(n==1)
		{
			cout<<"There is 1 account and no account is modified"<<endl;
		}else
		{
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}
	}else
	{
		cout<<count<<endl;
		for(i=0;i<count;i++)
		{
			cout<<s[ans[i]][0]<<" "<<s[ans[i]][1]<<endl;
		}

	}
	return 0;
}
