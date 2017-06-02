#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct node
{
    int at, cost;
    node() {}
    node(int _at, int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const node &a)const
    {
        return cost > a.cost;
    }
};
vector<node> adj[10006];
priority_queue<node> pq;
int dist[100000], n;

void dijkstra(int source)
{
    int i ;
    for(i=1; i<=n; i++)
        dist[i] = INF;

    dist[source] = 0;
    pq.push(node(source, 0));

    while(!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        if(u.cost != dist[u.at])
            continue;
        for(i=0; i<adj[u.at].size(); i++)
        {
            node v = adj[u.at][i];
            if(dist[v.at] > u.cost + v.cost)
            {
                dist[v.at] = u.cost + v.cost;
                pq.push(node(v.at, dist[v.at]));
            }
        }
    }
}
int main()
{
    int i, j, m, u, v, cost, source;

    printf("Please Enter the number of node: ");
    scanf("%d", &n);

    printf("Please Enter the number of edge: ");
    scanf("%d", &m);

    printf("Enter the edge and their cost:\n");
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u, &v, &cost);
        adj[u].push_back(node(v, cost));
        adj[v].push_back(node(u, cost));
    }

    printf("Enter the source: ");
    scanf("%d",&source);

    dijkstra(source);

    for(i=1; i<=n; i++)
    {
        if(dist[i] == INF && i != source)
            printf("Node %d is not connected with the graph\n",i);
        else
            printf("Shortest distance from source to %d is : %d\n", i, dist[i]);
    }

    return 0;
}
