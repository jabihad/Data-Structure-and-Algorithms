#include<bits/stdc++.h>
using namespace std;

int amount[1000006], sum[10000006];
int main()
{
    int i, j, n, query, box, t, a, b, x, y, r, p, q, k;

    printf("Please Enter the number of box: ");
    scanf("%d",&n);
    k = sqrt(n);
    for(i=0; i<n; i++)
    {
        printf("Enter the box number and amount:\n");
        scanf("%d%d",&box, &t);
        amount[box] += t;
        sum[box/k] += t;
    }
    printf("Enter the number of query: ");
    scanf("%d",&query);
    for(i=0; i<query; i++)
    {
        r = 0;
        scanf("%d%d",&a, &b);
        x = a/k;
        y = b/k;
        if(x == y)
        {
            for(j=a; j<=b; j++)
                r += amount[j];
        }
        else
        {
            p = k*(x + 1) - 1; /// end value of x
            q = k*y;           /// start value of y
            for(j=a; j<=p; j++)
                r += amount[j];
            for(j=q; j<=b; j++)
                r += amount[j];
            for(j=p+1; j<=q-1; j+=k)
                r += sum[j/k];
        }
        printf("Amount in the box %d to %d is : %d\n",a, b, r);
    }
    return 0;
}
