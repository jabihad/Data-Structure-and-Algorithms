#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<edge> adj;
int dis[10000000], n, flag;

void Bellmanford(int source)
{
    int i, step;
    for(i=1; i<=n; i++)
        dis[i] = INF;
    dis[source] = 0;
    for(step = 1; step<n; step++)
    {
        for(i = 0; i<adj.size(); i++)
        {
            if(dis[adj[i].u] + adj[i].w < dis[adj[i].v])
                dis[adj[i].v] = dis[adj[i].u] + adj[i].w;
        }
    }
    for(i = 0; i<adj.size(); i++)
    {
        if(dis[adj[i].u] + adj[i].w < dis[adj[i].v])
        {
            printf("Negative Cycle Detected\n");
            flag = 1;
            return;
        }
    }
}
int main()
{
    int i, m, u, v, cost, source;
    printf("Please Enter the number of node: ");
    scanf("%d",&n);

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u, &v, &cost);
        adj.push_back(edge(u, v, cost));
    }
    printf("Please Enter the source: ");
    scanf("%d",&source);

    Bellmanford(source);
    if(flag==0)
    {
        for(i=1; i<=n; i++)
        {
            if(dis[i] == INF)
                printf("Shortest distance from source to %d is : INFINITY\n",i);
            else
                printf("Shortest distance from source to %d is : %d\n", i, dis[i]);
        }
    }
    return 0;
}
