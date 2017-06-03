#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int d[10000], low[10000], parent[10000], root, ti;
set<int> Articulation_point;
set<int> :: iterator it;
bool visited[10000];

void Find_Articulation_Point(int u)
{
    int no_of_children, v;
    ti = ti + 1;
    low[u] = d[u] = ti;
    visited[u] = true;
    no_of_children = 0;

    for(int i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];

        if(v == parent[u])
            continue;

        if(visited[v])     /// This is a backedge
            low[u] = min(low[u], d[v]);

        if(!visited[v])    /// This is a tree edge
        {
            parent[v] = u;
            Find_Articulation_Point(v);
            low[u] = min(low[u], low[v]);

            if(d[u] <= low[v] && u != root)
                Articulation_point.insert(u);

            no_of_children = no_of_children + 1;
        }
        if(no_of_children > 1 && u == root)
            Articulation_point.insert(u);
    }
}

int main()
{
    int i, j, n, m, u, v;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("Please Enter the root: ");
    scanf("%d",&root);                  /// any node up to n can be given as node

    Find_Articulation_Point(root);

    printf("\nArticulation points are: ");

    for(it=Articulation_point.begin(); it!=Articulation_point.end(); it++)
        printf("%d ", *it);
    printf("\n");

    return 0;
}
