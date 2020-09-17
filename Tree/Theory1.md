

## Difference between binary tree and binary search tree

Binary tree: Tree where each node has up to two leaves
```
  1
 / \
2   3
```
Binary search tree: Used for searching. A binary tree where the left child 
contains only nodes with values less than the parent node, and where the right child 
only contains nodes with values greater than or equal to the parent.
```
    5
   / \
  3   6 
 / \   \
1   4   9 
```

## Tree
A tree is a connected, acyclic graph that consists of n nodes and n-1 edges.
Removing any edge from a tree divides it into two components, and adding any
edge to a tree creates a cycle. Moreover, there is always a unique path between
any two nodes of a tree.



The structure of a rooted tree is recursive: each node of the tree acts as the
root of a subtree that contains the node itself and all nodes that are in the
subtrees of its children. 


## Tree traversal
General graph traversal algorithms can be used to traverse the nodes of a tree.
However, the traversal of a tree is easier to implement than that of a general
graph, because there are no cycles in the tree and it is not possible to reach a
node from multiple directions.
The typical way to traverse a tree is to start a depth-first search at an arbitrary
node. The following recursive function can be used:

```
void dfs(int s, int e) {
    // process node s
    for (auto u : adj[s]) {
        if (u != e) dfs(u, s);
    }
}
```

The function is given two parameters: the current node s and the previous
node e. The purpose of the parameter e is to make sure that the search only
moves to nodes that have not been visited yet.
The following function call starts the search at node x:

dfs(x, 0);

In the first call e = 0, because there is no previous node, and it is allowed to
proceed to any direction in the tree.

### Dynamic programming
Dynamic programming can be used to calculate some information during a tree
traversal. Using dynamic programming, we can, for example, calculate in O(n)
time for each node of a rooted tree the number of nodes in its subtree or the
length of the longest path from the node to a leaf.

As an example, let us calculate for each node s a value count[s]: the number
of nodes in its subtree. The subtree contains the node itself and all nodes in
the subtrees of its children, so we can calculate the number of nodes recursively
using the following code:
```
void dfs(int s, int e) {
    count[s] = 1;
    for (auto u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        count[s] += count[u];
    }
}
```


## binary search tree implementation

```
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//Node *root; //declaring the root of the tree as global

//for creating a node in the heap memory and getting the address
Node *GetNewNode(int data)
{
    Node *newNode = new Node(); //malloc is used in c for allocating memory
    newNode->data = data;       //  (*newNode).data = data
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *Insert(Node *root, int data)
{
    //if tree is empty then create a new node
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);

    return root;
}

bool Search(Node *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else if (data > root->data)
        return Search(root->right, data);
}

int main()
{
    Node *root;  //decalring the root
    root = NULL; //setting the tree as emnpty

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);

    cout << Search(root, 1) << endl;  //false
    cout << Search(root, 10) << endl; //true
    cout << Search(root, 20) << endl; //true
    return 0;
}
```