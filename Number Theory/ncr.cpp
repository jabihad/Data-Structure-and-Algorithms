#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int ncr[MAX][MAX];
void NCR(int n)
{
    ncr[0][0] = 1;
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(j>i)ncr[i][j] = 0;
            else if(j == i || j==0)ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}
int main()
{
    int i, j, n,a, b;
    printf("Please Enter the limit of Combination: ");
    scanf("%d",&n);
    NCR(n);
    scanf("%d%d",&a, &b);
    printf("%d C %d is %d\n",a, b, ncr[a][b]);

    return 0;
}

