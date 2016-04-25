#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int a,b,c,jud;
bool maze[65][1300][130];
struct point
{
	point(int x,int y,int z):x(x),y(y),z(z){}
	int x,y,z;
};
queue<point> q;
int go[6][3]={	1,0,0,
				-1,0,0,
				0,1,0,
				0,-1,0,
				0,0,1,
				0,0,-1
				};

int BFS()
{
	int count=1;
	while(!q.empty())
	{
		point p=q.front();
		q.pop();
		int x=p.x,y=p.y,z=p.z;
		int i;
		int nx,ny,nz;
		for(i=0;i<6;i++)
		{
			nx=x+go[i][0];
			ny=y+go[i][1];
			nz=z+go[i][2];
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue;
			if(maze[nx][ny][nz]==false) continue;
			count++;
			maze[nx][ny][nz]=false;						//每一个状态，入队列就应该将其标记为false，以防再次入队
			q.push(point(nx,ny,nz));
		}
	}
	return count>=jud?count:0;
}

int main()
{
	memset(maze,false,sizeof(maze));
	int i,j,k,ans=0;
	cin>>b>>c>>a>>jud;

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			for(k=0;k<c;k++)
			{
				int temp;
				cin>>temp;
				maze[i][j][k]=(temp==1);
			}
		}
	}

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			for(k=0;k<c;k++)
			{
				if(maze[i][j][k])
				{
					maze[i][j][k]=false;
					q.push(point(i,j,k));
					ans+=BFS();
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
