#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 8;
vector < int > g[M];
bool vis[M];

void dfs(int s){
    vis[s] = true;
    for(int i = 0; i < g[s].size(); i++){
        int v = g[s][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    int n, m;

    cin >> n >> m; //n = node , m = edges
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int src, des;
    cin >> src >> des;
    dfs(src);
    if(vis[des])
        cout << "there is a path exist" << endl;
    else cout << "no path exist" << endl;
    return 0;
}