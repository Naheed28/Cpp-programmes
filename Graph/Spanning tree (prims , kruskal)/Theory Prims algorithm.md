For better details please go to this site
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/


Prim’s Algorithm
Prim’s Algorithm also use Greedy approach to find the minimum spanning tree. In Prim’s Algorithm we grow the spanning tree from a 
starting position. Unlike an edge in Kruskal's, we add vertex to the growing spanning tree in Prim's.

Algorithm Steps:

Maintain two disjoint sets of vertices. One containing vertices that are in the growing spanning tree and other that are not in 
the growing spanning tree.
Select the cheapest vertex that is connected to the growing spanning tree and is not in the growing spanning tree and 
add it into the growing spanning tree. This can be done using Priority Queues. Insert the vertices, that are connected 
to growing spanning tree, into the Priority Queue.
Check for cycles. To do that, mark the nodes which have been already selected and insert only those nodes in the Priority 
Queue that are not marked.
Consider the example below:



Implementation:with adjacency list

```cpp
#include<bits/stdc++.h>
#define PII pair<int,int>

using namespace std ;

const int MAX = 1e5 + 5 ;
bool marked[MAX] ;
vector <PII> adj[MAX] ;  //vector <pair<int,int> > adj[MAX] ;

int prim(int x)
{
	priority_queue <PII ,vector <PII> ,greater<PII>> Q ;
	//for making a minheap,which means that the smallest value will be given the most priority
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
}

```
