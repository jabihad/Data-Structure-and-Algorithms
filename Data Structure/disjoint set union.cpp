#include<bits/stdc++.h>
using namespace std;

int par[1000006];
int find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void join(int p, int q)
{
    int u, v;
    u = find(p);
    v = find(q);
    if(u != v)
        par[u] = v;
}

int main()
{
    int n, m, query, u, v, p, q;
    set<int> s;

    printf("Please Enter total number of node: ");

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        par[i] = i;       /// Setting every number as their parent

    printf("Please Enter total number of edge: ");

    scanf("%d",&m);

    printf("Now Enter the edge:\n");
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u, &v);
        join(u,v);
    }

    printf("Enter the number of query: ");

    scanf("%d",&query);

    printf("Now enter the query: \n");
    for(int i=1; i<=query; i++)
    {
        scanf("%d%d",&p,&q);
        if(find(p)==find(q))
            printf("%d and %d are in the same set\n",p, q);
        else
            printf("%d and %d are in the different set\n",p, q);
    }
    for(int i=1; i<=n; i++){
        int temp = find(i);    ///This must be called to build each element's final parent
        s.insert(par[i]);
    }

    printf("\nTotal number of disjoint set is: %d\n",s.size());

    return 0;
}
