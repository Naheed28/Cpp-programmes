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

