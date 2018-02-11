#include<bits/stdc++.h>
#define ll long long int
using namespace std;


/// will print 1st n number even size palindrome
/// if n==13 palindromes are : 11 22 33 44 55 66 77 88 99 1001 1111 1221 1331
int main()
{
    int n, m;
    scanf("%d", &n);
    ll sum = 0;
    for(ll i = 1; i<=n; i++)
    {
        ll temp = i, now = i;
        while(temp)
        {
            now = now * 10ll + temp%10;
            temp /= 10;
        }
        cout<<now<<endl;
    }

    return 0;
}
