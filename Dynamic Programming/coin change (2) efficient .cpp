#include<bits/stdc++.h>
using namespace std;

int dp[10][8000], coin[]={50, 25, 10, 5, 1}, make, n;
int call(int i, int amount)
{
    if(i>=n){
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    int ret1=0, ret2=0;
    if(amount-coin[i]>=0) ret1 = call(i, amount-coin[i]);
    ret2 = call(i+1, amount);
    return dp[i][amount] = ret1 + ret2;
}

int main()
{
    n = 5;
    memset(dp, -1, sizeof(dp));
    while(cin>>make)
    {
        int res = call(0, make);

        cout<<res<<endl;
    }

    return 0;
}
