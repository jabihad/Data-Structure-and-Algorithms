#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,w;
    node() {}
    node(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const node &a) const
    {
        return w<a.w;
    }
};

vector<node> e;
int p[10005];

int find(int x)
{
    if(p[x]==x)
        return x;
    return p[x] = find(p[x]);
}
int kruskal()
{
    int i,j,sz,a,b,ans = 0;

    sort(e.begin(),e.end());
    sz = e.size();

    for(j=0; j<sz; j++)
    {
        a = find(e[j].u);
        b = find(e[j].v);
        if(a!=b)
        {
            p[a] = b;
            ans += e[j].w;
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
        e.push_back(node(u,v,w));
        e.push_back(node(v,u,w));
        p[i] = i;
    }

    ans = kruskal();

    printf("Cost of minimum spanning tree is : %d\n",ans);

    return 0;
}

