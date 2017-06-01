#include<bits/stdc++.h>
#define mx 678910
using namespace std;

int r[mx], p[mx], s[mx];
int cut_rod(int n)
{
    int i, q, temp;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q = 0;
    else
    {
        q = INT_MIN;
        for(i=1; i<=n; i++)
        {
            temp = p[i] + cut_rod(n-i);
            if(temp > q)
            {
                s[n] = i;
                q = temp;
            }
        }
    }
    r[n] = q;

    return q;
}
void print(int n)
{
    while(n>0)
    {
        printf("%d ",s[n]);
        n = n-s[n];
    }
}
int main()
{
    int i, j, n;
    printf("Please give the rod size: ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
        r[i] = INT_MIN;
    printf("\nPlease give the price for different length of rod:\n\n");
    for(i=1; i<=10; i++)
        scanf("%d",&p[i]);
    printf("\nMaximum revenue for %d meter is %d\n",n,cut_rod(n));

    printf("\nTo get maximum revenue the rod should be cut at : ");

    print(n);

    printf("\n");

    return 0;
}

