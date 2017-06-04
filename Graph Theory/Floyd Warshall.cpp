#include<bits/stdc++.h>
#define MAX 6789
#define INF 9999999
using namespace std;

int dist[MAX][MAX], next[MAX][MAX], n;
vector<int> path;
void FloydWarshall()
{
    int i, j, k;

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
void find_path(int i, int j)
{
    path.push_back(i);
    while(i != j )
    {
        i = next[i][j];
        path.push_back(i);
    }
    for(i=0; i<path.size(); i++)
        printf("%d ",path[i]);
}
int main()
{
    int i, j, m, u, v, w, source, dest;

    printf("Please Enter the number of node: ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else
            {
                dist[i][j] = INF;
                dist[j][i] = INF;
            }
            next[i][j] = j;
        }
    }

    printf("Please Enter the number of edge: ");
    scanf("%d",&m);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u, &v, &w);
        dist[u][v] = w;
    }
    FloydWarshall();

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(dist[i][j] == INF)
                printf("There is no way from %d to %d\n",i, j);
            else
                printf("Shortest distance from %d to %d is %d\n",i, j, dist[i][j]);
        }
    }

    printf("\nPlease Enter Source and Destination: ");
    scanf("%d%d",&source, &dest);
    if(dist[source][dest] == INF)
        printf("There is no path from %d to %d\n",source, dest);
    else
    {
        printf("Shortest path from %d to %d is: ",source, dest);
        find_path(source, dest);
        printf("\n");
    }

    return 0;
}
