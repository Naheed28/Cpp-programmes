Watch this video just for simulation
https://youtu.be/eL-KzMXSXXI


There are different ways to solve the algo.

## 1st approach

Graph Algo book(shafeet):
Here we start from the beginning node which contains 0 indegree.

Programming tips:

There is no need to delete edges like in image or pseudocode when writing code, using a dictionary to keep track of the indegree of each node
and delete the edge by reducing the indegree of the node.

```pseudo

procedure topsort (G):

    L -> Empty list that will contain the sorted elements 
    S -> Set of all nodes with zero indegree

    while S is non-empty
        remove a node u from S
        L.add (u)

        for each adjacent node v of u do 
            remove edge (u, v) from the graph 
            if v has no other incoming edges 
                S.add (v)
            end if
        end for

    end while
    
```

```cpp
#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
vector < int > g[M], res;
int indegree[M];

int main()
{
    //freopen("in.txt", "r", stdin);
    memset(indegree, 0, sizeof indegree);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){ //1 based graph
        for(int j = 0; j < g[i].size(); i++){
            int v = g[i][j];
            indegree[v]++;
        }
    }
    queue < int > q; // for printing input order use priority_queue.
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    if(res.size() != n) cout << "Topsort Impossible" << endl;
    else{
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}

```


<br>
<br>

<br>
<br>

## 2nd approach

## Better approach : Using DFS

https://cp-algorithms.com/graph/topological-sort.html

Here is an implementation which assumes that the graph is acyclic, i.e. the desired topological ordering exists. If necessary, you can easily check that the graph is acyclic, as described in the article on depth-first search.

```cpp
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

```

