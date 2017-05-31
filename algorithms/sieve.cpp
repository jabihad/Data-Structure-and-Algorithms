#include<bits/stdc++.h>
using namespace std;

int mark[1000000],nprime,prime[100000];

void sieve (int n)
{
    int i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4; i<=n; i+=2)mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=2*i)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
int main()
{
    int i,j;
    printf("Please Enter the number up to which you want to find all prime numbers: ");
    scanf("%d",&i);
    sieve(i);

    for(j=0; j<nprime; j++)
        printf("%d ",prime[j]);

    printf("\n");
    return 0;
}
