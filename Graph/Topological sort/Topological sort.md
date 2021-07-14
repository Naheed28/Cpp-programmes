
Graph Algo book(shafeet):
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

