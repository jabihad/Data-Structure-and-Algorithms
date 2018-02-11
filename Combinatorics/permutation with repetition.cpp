#include<bits/stdc++.h>
using namespace std;

int ans[5000][5000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, k, n, r, perm;

    cin>>n>>r;

    /// n = total numbers, r = how many numbers you want to take
    /// if n==2 && r==3 ;
    /// There will be n^r = 2 ^ 3 = 8 permutation, they are :
    /// 1 1 1
    /// 1 1 2
    /// 1 2 1
    /// 1 2 2
    /// 2 1 1
    /// 2 1 2
    /// 2 2 1
    /// 2 2 2
    perm = 1;
    for(i=1; i<=r; i++)
        perm *= n;

    for(i=1; i<perm; i++)
    {
        for(j=0; j<r; j++)ans[i][j] = ans[i-1][j];

        for(j=r-1; j>=0; j--)
        {
            ans[i][j] = (ans[i][j]+1) % n;
            if(ans[i][j])
                break;
        }
    }
    /// line 30-40 generate the following
    /// 0 0 0
    /// 0 0 1
    /// 0 1 0
    /// 0 1 1
    /// 1 0 0
    /// 1 0 1
    /// 1 1 0
    /// 1 1 1
    /// thats why to get actual permutation we need to add 1 at line 56

    for(i=0; i<perm; i++)
    {
        for(j=0; j<r; j++)
        {
            cout<<ans[i][j]+1<<" ";
        }
        cout<<endl;
    }

    return 0;
}
