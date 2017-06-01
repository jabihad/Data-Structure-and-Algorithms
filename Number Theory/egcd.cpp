#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y)
{
    if(a==0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);

    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}
int main()
{
    int a, b, x, y, gcd;
    printf("Please Enter the number: ");
    scanf("%d%d",&a,&b);
    gcd = egcd(a, b, x, y);
    printf("GCD of %d and %d is %d\n\n",a, b, gcd);
    printf("EGCD is %d %d\n",x, y);

    return 0;
}
