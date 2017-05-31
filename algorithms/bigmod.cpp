#include<bits/stdc++.h>
using namespace std;

int bigmod(int a,int b,int M)
{
    if(b==0)return 1 % M;
    int x = bigmod(a, b/2, M);
    x = (x*x) % M;
    if(b%2 == 1)x = (x*a) % M;
    return x;
}
int main()
{
    int a, b, M, res;
    printf("Please Enter the number a ,its power b and modulo M : ");
    scanf("%d%d%d",&a,&b,&M);
    res = bigmod(a,b,M);
    printf("Modulus is : %d\n",res);

    return 0;
}
