#include<bits/stdc++.h>
using namespace std;

vector<int>l, adj[10000];
queue<int>q;
int indegree[10000000], n;

void top_sort()
{
    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        l.push_back(u);

        for(int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            indegree[v]--;

            if(indegree[v]==0)
                q.push(v);
        }
    }
}

int main()
{
    int i, sz, k, m, u, v;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);
    for(int i =1; i<=n; i++)
        indegree[i] = 0;

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);

    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&u, &v);
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(i=1; i<=n; i++)
        if(indegree[i]==0)
            q.push(i);

    top_sort();

    sz = l.size();

    printf("Topological order is: ");
    for(i=0; i<sz; i++)
        printf("%d ",l[i]);
    printf("\n");

    return 0;
}
