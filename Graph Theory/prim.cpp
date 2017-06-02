#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

struct node
{
    int at,cost;
    node() {}
    node(int _at,int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const node &a) const
    {
        return cost>a.cost;
    }
};

vector<node> adj[10001];
int taken[10001], cost[10001], source;

int prim()
{
    int ans = 0;
    priority_queue<node>pq;

    cost[source] = 0;        /// source is the node where prim will start
    pq.push(node(source,0));

    while(!pq.empty())
    {
        node e = pq.top();
        pq.pop();

        int u = e.at;
        if(taken[u])continue;

        ans += e.cost;
        taken[u] = 1;

        for(int i=0; i<adj[u].size(); i++)
        {
            node f = adj[u][i];
            int v = f.at;
            if(taken[v])continue;
            if(cost[v]>f.cost)
            {
                cost[v] = f.cost;
                pq.push(node(v,cost[v]));
            }
        }
    }

    return ans;
}
int main()
{
    int i, j, k, l, m, n, u,v, w, ans=0;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);

    printf("Please Enter the number of edges: ");
    scanf("%d",&m);

    printf("Now Enter the edges and cost between them:\n");

    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(node(v,w));
        adj[v].push_back(node(u,w));
        cost[i] = INF;
    }

    printf("Enter the source: ");
    scanf("%d",&source);

    ans = prim();

    printf("Cost of minimum spanning tree is : %d\n",ans);

    return 0;
}

