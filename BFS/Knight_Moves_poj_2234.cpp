#include <iostream>
#include<queue>
#include<string.h>
#include<stdio.h>

using namespace std ;

int cell[9][9];
int d[9][9] , vis[9][9] ;

int fx[] = {1,1,2,2,-1,-1,-2,-2} ;
int fy[] = {2,-2,1,-1,2,-2,1,-1} ;
 

void bfs(int x ,int y)
{
	vis[x][y] = 1 ;
	queue<pair<int , int> > q ;
	q.push(make_pair(x,y)) ;

	while(!q.empty())
	{
		pair<int ,int> top = q.front() ;
		q.pop() ;

		for(int i = 0 ; i < 8 ;i++)
		{
			int px = top.first + fx[i] ;
			int py = top.second +fy[i] ;
			if(px>0 and px <= 8 and py>0 and py <= 8 and cell[px][py]!=-1 and vis[px][py]==0)
			{
				vis[px][py] = 1 ;
				d[px][py] = d[top.first][top.second] + 1 ;
				q.push(make_pair(px,py)) ;
			} 
		}
	}



}

int main()
{
	string s1 , s2 ;
	while(cin >> s1 >> s2 )
	{
		if(s1=="" )break;
		
		bfs(s1[0] - 96 , s1[1] -48) ;
		if(vis[s2[0] - 96][s2[1] -48] == 1)
		{
			cout <<"To get from "<<s1<<" to "<<s2<<" takes "<<d[s2[0] - 96][s2[1] -48]<<" knight moves."<<endl ;
			
		}
		memset(cell , 0 , sizeof cell) ;
		memset(d, 0 , sizeof d) ;
		memset(vis , 0 , sizeof vis) ;

	
	}

	return 0 ;
}