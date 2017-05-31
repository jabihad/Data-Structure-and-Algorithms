#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int i, res = n;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n /= i;
            }
            res -= res/i;
        }
    }
    if(n > 1)
    {
        res -= res/n;
    }
    return res;
}

int main()
{
    int i, j, n, res;
    printf("Please Enter the number  which you want to find Euler's Totient function: ");
    scanf("%d",&n);
    res = phi(n);
    printf("\nThe total number of Co-Prime of %d is %d\n",n,res);

    return 0;
}

