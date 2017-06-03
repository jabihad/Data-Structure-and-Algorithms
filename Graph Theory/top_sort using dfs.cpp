#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int  ti, dis[10000], fin[10000], color[10000];
stack<int> s;

void dfs(int source)
{
    int u = source;
    ti = ti + 1;
    dis[u] = ti;
    color[u] = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(color[v]==0)
        {
            dfs(v);
        }
    }
    s.push(u);
    color[u] = 2;
    ti = ti + 1;
    fin[u] = ti;
}
int main()
{
    int i, k, n, m, u, v, source;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);

    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&u, &v);
        adj[u].push_back(v);
    }
    for(i=1; i<=n; i++)
    {
        if(color[i] == 0)
            dfs(i);
    }

    printf("Topological order is: ");
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}
