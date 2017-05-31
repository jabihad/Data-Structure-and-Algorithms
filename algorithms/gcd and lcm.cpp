#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) /// recursive
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int GCD(int a,int b) /// iterative
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b)
{
    int temp = gcd(a,b);
    return (a*b)/temp;
}
int main()
{
    int a, b, res;

    printf("Please Enter the number a and b: ");

    scanf("%d%d",&a,&b);

    res = GCD(a,b);

    printf("\nGCD of %d and %d is :  %d\n\n", a, b, res);
    printf("LCM of %d and %d is :  %d\n", a, b, lcm(a,b));

    return 0;
}
