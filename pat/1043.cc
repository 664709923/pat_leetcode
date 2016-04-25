#include<iostream>
#include<algorithm>
#define MAX 1005

using namespace std;

int pre[MAX];
int in[MAX];
int n;
struct node
{
	struct node *l,*r;
	int data;
};

bool f=true;
void postOrder(node *T)
{
	if(T->l) postOrder(T->l);
	if(T->r) postOrder(T->r);
	if(T)
	{
		if(f)
		{
			cout<<T->data;
			f=false;
		}else
		{
			cout<<" "<<T->data;
		}
	}
}

bool flag=false;
node* build(int s1,int e1,int s2,int e2,bool re)
{
	int i,index;
	node *p=new node;
	p->l=p->r=NULL;
	p->data=pre[s1];
	if(re)
	{
		for(i=e2;i>=s2;i--)
		{
			if(in[i]==pre[s1])
			{
				index=i;
				break;
			}
		}
	}else
	{
		for(i=s2;i<=e2;i++)
		{
			if(in[i]==pre[s1])
			{
				index=i;
				break;
			}
		}
	}

	if(index==e2+1) flag=true;
	if(index!=s2)
	{
		if(re) p->l=build(s1+1,s1+index-s2,s2,index-1,true);
		else p->l=build(s1+1,s1+index-s2,s2,index-1,false);
	}
	if(index!=e2)
	{
		if(re) p->r=build(s1+index-s2+1,e1,index+1,e2,true);
		else p->r=build(s1+index-s2+1,e1,index+1,e2,false);
	}
	return p;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>pre[i];
		in[i]=pre[i];
	}
	if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<pre[0]<<endl;
	}
	bool re=false;
	if(pre[0]>pre[1]) sort(in,in+n);
	else
	{
		re=true;
		sort(in,in+n,cmp);
	}

	node *T;
	if(re)	T=build(0,n-1,0,n-1,false);
	else T=build(0,n-1,0,n-1,true);
	if(flag)
	{
		cout<<"NO"<<endl;
	}else
	{
		cout<<"YES"<<endl;
		postOrder(T);
	}
	return 0;
}
