#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stack>

using namespace std;

int num;
bool first=true;
struct Node
{
	Node(int val): data(val),l(NULL),r(NULL){}
	int data;
	Node *l,*r;
};

void postOrder(Node *T)
{
	if(T)
	{
		postOrder(T->l);
		postOrder(T->r);
		if(first)
		{
			printf("%d",T->data);
			first=false;
		}else
		{
			printf(" %d",T->data);
		}
	}
}

int main()
{
	//Node* p = (Node*)malloc(sizeof(Node));
	int i,n,node;
	char oper[5];
	scanf("%d",&n);
	int tree[n*2];
	memset(tree,0,sizeof(tree));
	for(i=0;i<2*n;i++)
	{
		scanf("%s",oper);
		if(strcmp(oper,"Push")==0)
		{
			scanf("%d",&tree[i]);
		}else
		{
			tree[i]=0;
		}
	}

	Node* root = (Node*)malloc(sizeof(Node));
	root->data=tree[0];
	stack<Node*> biTree;
	while(!biTree.empty()) biTree.pop();
	biTree.push(root);
	Node* p = root;
	bool flag=true;
	for(i=1;i<2*n;i++)
	{
		if(tree[i])
		{
			Node *temp=new Node(tree[i]);
			biTree.push(temp);
			if(flag) p->l=temp;
			else p->r=temp;
			p=temp;
			flag=true;
		}else
		{
			flag=false;
			p=biTree.top();
			biTree.pop();
		}
	}

	postOrder(root);
	return 0;
}
