#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10006];
int visited[10006], dis[10006];
void bfs(int source)
{
    int u, v, i;
    queue<int> q;

    q.push(source);
    visited[source] = 1;
    dis[source] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            if(visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
                dis[v] = dis[u] + 1;
            }
        }
    }
}
int main()
{
    int i, j, n, m, u, v, source;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        visited[n] = 0;
        adj[i].clear();
    }

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);

    printf("Now Enter the edges:\n");
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("Enter the source: ");
    scanf("%d",&source);
    bfs(source);
    for(i=1; i<=n; i++)
    {
        if(dis[i] == 0 && i != source)
            printf("Node %d is not connected with the graph\n",i);
        else
            printf("Shortest distance from source to %d is : %d\n", i, dis[i]);
    }

    return 0;
}

