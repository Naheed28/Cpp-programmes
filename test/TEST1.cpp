#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

vector<int>adj[30005] ;
vector<int>weight[30005] ;


int x  ;//for recording the first farthest node cost

bool vis[30005] ;
int d[30005] ,d1[30005] ; //distance from source


int bfs1(int s)
{
	vis[s] = true ;
	queue<int> q ;
	q.push(s) ;
	d[s] = 0 ; //distance from source 

	int max_dis = -1 ;
	int farthest_node = 0 ;

	while(!q.empty())
	{
		int u ;
		u = q.front() ;
		vis[u] = true ;
		q.pop() ;
		for(int i = 0 ; i  < adj[u].size() ;i++)
		{
			int v= adj[u][i] ;

			if(!vis[v])
			{
				q.push(v) ;
				int wt = weight[u][i] ;
				d[v] = d[u] + wt ; //adding the weight
				if(d[v] > max_dis)
				{
					max_dis = d[v] ;
					farthest_node =  v ;
 				}
 			}

		}
	}
	return farthest_node ; //returning the farthest node


}
void bfs2(int s)
{
	vis[s] = true ;
	queue<int> q ;
	q.push(s) ;
	d[s] = 0 ; //distance from source 

	int max_dis = -1 ;
	int farthest_node = 0 ;

	while(!q.empty())
	{
		int u ;
		u = q.front() ;
		vis[u] = true ;
		q.pop() ;
		for(int i = 0 ; i  < adj[u].size() ;i++)
		{
			int v= adj[u][i] ;

			if(!vis[v])
			{
				q.push(v) ;
				int wt = weight[u][i] ;
				d[v] = d[u] + wt ; //adding the weight
				if(d[v] > max_dis)
				{
					max_dis = d[v] ;
					farthest_node =  v ;
 				}
 			}

		}
	}
//	return farthest_node ; //returning the farthest node


}

void bfs3(int s)
{
	vis[s] = true ;
	queue<int> q ;
	q.push(s) ;
	d1[s] = 0 ; //distance from source 

	int max_dis = -1 ;
	int farthest_node = 0 ;

	while(!q.empty())
	{
		int u ;
		u = q.front() ;
		vis[u] = true ;
		q.pop() ;
		for(int i = 0 ; i  < adj[u].size() ;i++)
		{
			int v= adj[u][i] ;

			if(!vis[v])
			{
				q.push(v) ;
				int wt = weight[u][i] ;
				d1[v] = d1[u] + wt ; //adding the weight
				if(d1[v] > max_dis)
				{
					max_dis = d1[v] ;
					farthest_node =  v ;
 				}
 			}

		}
	}
	//return farthest_node ; //returning the farthest node


}


int main()
{
	int t ;
	scanf("%d",&t) ;
	for(int i = 0 ; i < t ; i++)
	{
		int n ;
		scanf("%d" , &n);
		for(int j = 0 ; j < n-1 ;j++)
		{ 
			int u , v, w ;
			scanf("%d %d %d" ,&u,&v,&w) ;
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
			weight[u].push_back(w) ;
			weight[v].push_back(w) ;
		}
		memset(vis , 0 , sizeof vis) ;
		memset(d , 0 , sizeof d) ;

		int first_node = bfs1(0) ; //first node in the tree diameter
		//x = d[first_node] ;

		memset(vis , 0 , sizeof vis) ;
		memset(d , 0 , sizeof d) ;

		bfs2(first_node) ;
		memset(vis , 0 , sizeof vis) ;
		bfs3(first_node) ;
		//d[n-1] = x ;
		printf("Case %d:\n" ,i+1) ;
		for(int i = 0 ; i < n ; i++ )
			printf("%d\n" , max(d[i],d1[i]));

		memset(adj , 0 , sizeof adj) ;//clearing the vector
		memset(weight , 0 , sizeof weight) ;



	}



	return 0 ;
}