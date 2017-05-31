#include<bits/stdc++.h>
#define ll long long int
#define MAX 678990
using namespace std;

ll prime[MAX],nprime,mark[MAX];

void sieve()
{
    ll i, j, n=MAX, limit = sqrt(n);
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=i*2)
                    mark[j]=1;
            }
        }
    }
}
int segment_sieve(ll a,ll b)
{
    ll p = 0;
    if(a==1)a=2;
    memset(mark,0,sizeof mark);
    ll i,j,sqrtb = sqrt(b)+2;
    for(i=0; i<nprime && prime[i]<=sqrtb; i++)
    {
        ll j = prime[i]*prime[i];
        if(j<a)j=((a+prime[i]-1)/prime[i])*prime[i];/// ceil by (a+b-1)/b
        for(; j<=b; j+=prime[i])
            mark[j-a]=1;
    }
    for(i=a; i<=b; i++)
    {
        if(!mark[i-a])
            p++;
    }
    return p;
}
int main()
{
    ll a, b, res;

    sieve();

    printf("Please Enter the number a and b\n");
    scanf("%lld%lld",&a,&b);

    printf("The total number of primes between %lld and %lld is: ",a,b);

    res = segment_sieve(a,b);

    printf("%lld\n",res);

    return 0;
}
