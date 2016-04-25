#include<stdio.h>

typedef struct
{
	int addr;
	int data;
	int next;
}node,*LinkList;

int main()
{
	int i,j,n,m;
	int head,length,k;
	scanf("%d%d%d",&head,&length,&k);
	node temp;
	LinkList l = new node[length];
	//(node*)malloc(length*sizeof(node));
	//new node[length];
	for(i=0;i<length;i++)
	{
		scanf("%d%d%d",&l[i].addr,&l[i].data,&l[i].next);
	}

	m=i=0;
	n=head;
	while(i<length)
	{
		for(j=i;j<length;j++)
		{
			if(l[j].addr==n)
			{
				m++;
				n=l[j].next;
				temp=l[j];
				l[j]=l[i];
				l[i]=temp;
				i++;
				break;
			}
			if(n==-1)
			break;
		}
		if(n==-1)
		break;
	}
	length=m;

	if(k==1)
	{
		for(i=0;i<length-1;i++)
		{
			printf("%05d %d %05d\n",l[i].addr,l[i].data,l[i].next);
		}
		printf("%05d %d %d\n",l[i].addr,l[i].data,l[i].next);
	}
	else
	{
		for(i=0;i<length/k-1;i++)
		{
			for(j=0;j<k-1;j++)
			{
				printf("%05d %d %05d\n",l[(i+1)*k-1-j].addr,l[(i+1)*k-1-j].data,l[(i+1)*k-2-j].addr);
			}
			printf("%05d %d %05d\n",l[i*k].addr,l[i*k].data,l[(i+2)*k-1].addr);
		}

		for(j=0;j<k-1;j++)
		{
			printf("%05d %d %05d\n",l[(i+1)*k-1-j].addr,l[(i+1)*k-1-j].data,l[(i+1)*k-2-j].addr);
		}
		printf("%05d %d %d\n",l[i*k].addr,l[i*k].data,l[(i+1)*k-1].next);

		if(length%k>0)
		{
			for(i=length/k*k;i<length-1;i++)
			{
				printf("%05d %d %05d\n",l[i].addr,l[i].data,l[i].next);
			}
			printf("%05d %d %d\n",l[i].addr,l[i].data,l[i].next);
		}
	}



	return 0;
}

/*

00100 7 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
22222 10 33333

*/

