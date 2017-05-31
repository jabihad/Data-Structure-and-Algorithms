#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;

int phi[MAX], mark[MAX];
void sievephi(int n)
{
    int i, j;
    for(i=1; i<=n; i++)
        phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(i=2; i<=n; i++)
        if(!mark[i]) /// if i is prime
        {
            for(j=i; j<=n; j += i)
            {
                mark[j] = 1;
                phi[j] = phi[j] / i * (i-1);
            }
        }
}

int main()
{
    int i, j, n;
    printf("Please Enter the number up to which you want to find Euler's Totient function: ");
    scanf("%d",&n);
    sievephi(n);
    for(i=1; i<=n; i++)
        printf("The total number of Co-Prime of %d is %d\n",i,phi[i]);

    return 0;
}
