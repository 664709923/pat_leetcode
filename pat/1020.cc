//根据树的后序和中序遍历序列，创建树
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct Node
{
	struct Node* l;
	struct Node* r;
	int data;
};

int post[30],in[30];

Node* build(int s1,int e1,int s2,int e2)
{
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=post[e1];
	p->l=p->r=NULL;
	int root_index;
	for(int i=s2;i<=e2;i++)
	{
		if(post[e1]==in[i])
		{
			root_index=i;
			break;
		}
	}
	if(root_index!=s2)
	{
		p->l=build(s1,s1+(root_index-s2)-1,s2,root_index-1);
	}
	if(root_index!=e2)
	{
		p->r=build(s1+(root_index-s2),e1-1,root_index+1,e2);
	}
	return p;
}

void preOrder(Node * T)
{
	if(T)
		printf("%d ",T->data);
	if(T->l)
		preOrder(T->l);
	if(T->r)
		preOrder(T->r);
}

void level(Node *T)
{
	queue<Node*> q;
	while(!q.empty()) q.pop();
	printf("%d",T->data);
	if(T->l) q.push(T->l);
	if(T->r) q.push(T->r);
	while(!q.empty())
	{
		Node* p = q.front();
		q.pop();
		printf(" %d",p->data);
		if(p->l) q.push(p->l);
		if(p->r) q.push(p->r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}

	Node* T=build(0,n-1,0,n-1);
	level(T);
	return 0;
}
