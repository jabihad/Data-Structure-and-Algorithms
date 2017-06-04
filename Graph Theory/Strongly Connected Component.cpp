#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000], reverse_adj[1000], component[10000];
stack<int> s;
bool color[10000], visited[10000];
int n, mark;

void dfs(int source)
{
    int u = source;
    color[u] = true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(color[v] == false)
        {
            dfs(v);
        }
    }
    s.push(u);
}
void dfs2(int u)
{
    component[mark].push_back(u); /// save nodes of the new component
    visited[u] = true;
    for(int i=0; i<reverse_adj[u].size(); i++)
    {
        int v = reverse_adj[u][i];
        if(visited[v] == false)
        {
            dfs2(v);
        }
    }
}
void findSCC()
{
    for(int i=1; i<=n; i++)
    {
        if(color[i] == false)
            dfs(i);
    }
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        if(visited[u] == false)
        {
            mark = mark + 1;   /// A new component found
            dfs2(u);
        }
    }
}
int main()
{
    int i, j, m, u, v;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&u, &v);
        adj[u].push_back(v);
        reverse_adj[v].push_back(u);
    }
    findSCC();
    for(i=1; i<=mark; i++)
    {
        printf("%dth Component : ",i);
        for(j=0; j<component[i].size(); j++)
        {
            printf("%d ",component[i][j]);
        }
        printf("\n");
    }

    return 0;
}
