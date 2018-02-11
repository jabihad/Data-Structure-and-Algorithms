#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/// will print 1st n number even size palindrome
/// if n==13 palindromes are : 11 22 33 44 55 66 77 88 99 1001 1111 1221 1331
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;

    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        /** convert i into string**/
        stringstream ss;
        ss<<i;
        string str=ss.str();
        string temp=str;

        reverse(temp.begin(),temp.end());/// reverse this string
        str=str+temp;                    /// now append it with previous string

        /**now convert this string into integer**/

        ll num;
        ss.str(str);///take this string from str;
        ss>>num;    ///now move this into a number;

        cout<<num<<endl;
    }


return 0;
}
