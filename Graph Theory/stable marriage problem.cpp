#include<bits/stdc++.h>
using namespace std;

int Rank[300][300], cur[300], boy[300][300], girl[300][300], next[300];
int main()
{
    int i, j, k, l, m, n, t, b, g;
    queue<int> q;

    printf("Enter number of test cases: ");
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        printf("Enter number of boys and girls: ");
        scanf("%d", &n);
        memset(cur, 0, sizeof(cur));

        for(j=1;j<=n;j++){
            printf("Enter %d th boy's preference: ", j);
            for(k=1;k<=n;k++){
                scanf("%d", &boy[j][k]);
            }
            q.push(j);
            next[j] = 1;                           /// will save whom boy already has proposed
        }

        for(j=1;j<=n;j++){
            printf("Enter %d th girl's preference: ", j);
            for(k=1;k<=n;k++){
                scanf("%d", &girl[j][k]);
                Rank[j][girl[j][k]] = k;           /// Ranking girl's preference
            }
        }

        while(!q.empty()){
            b = q.front();
            g = boy[b][next[b]++];
            if(cur[g]==0){                         /// If girl is not married
                cur[g] = b;
                q.pop();
            }
            else if(Rank[g][b]<Rank[g][cur[g]])    /// New proposal's rank is better than current husband
            {
                q.pop();
                q.push(cur[g]);
                cur[g] = b;
            }
        }
        printf("Stable Marriage solution for Case %d is: ", i);
        for(j=1;j<=n;j++){
            printf("(%d %d)", cur[j], j);
            if(j<n)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
