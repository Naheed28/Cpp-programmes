#include<bits/stdc++.h>
#define PII pair<int,int>

using namespace std ;

const int MAX = 1e5 + 5 ;
bool marked[MAX] ;
vector <PII> adj[MAX] ;  //vector <pair<int,int> > adj[MAX] ;

int prim(int x)
{
	priority_queue <PII ,vector <PII> ,greater<PII>> Q ;//for making a minheap,which means that the smallest value will be given the most priority
														//priority_queue <PII> Q ; for max heap...
														//long long int can be used for higher value
	int y ;
	int minimumCost(0) ;

	Q.push(make_pair(0 , x)) ;

	while (!Q.empty())
	{
		//selecting the edge with minimum weight
		PII p = Q.top();
		Q.pop();
		x = p.second ;
		//checking for cycle
		if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0 ; i < adj[x].size();i++)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
	}
	return minimumCost ;


}




int main()
{
	int edge(0) , node(0) ;
	cin >> node >> edge ;

	for(int i = 0 ; i < edge ;i++)
	{
		int x , y , weight ;
		cin >> x >> y >> weight ;

		adj[x].push_back(make_pair(weight , y)) ;
		adj[y].push_back(make_pair(weight , x)) ;
		
	}

	//selecting 1 as starting node ;
	int minimumCost = prim(1) ;
	cout << minimumCost <<endl ;
	return 0 ;



	return 0 ;
}