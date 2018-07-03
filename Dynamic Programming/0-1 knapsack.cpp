#include<bits/stdc++.h>
#define MAX_N 100
#define MAX_W 1000
using namespace std;

int n, cap;
int dp[MAX_N+1][MAX_W+1];
int weight[MAX_N+1], cost[MAX_N+1];
int func(int i, int w)
{
    if(i==n+1)return 0;

    if(dp[i][w]!=-1)return dp[i][w];

    int profit1=0, profit2=0;

    if(w+weight[i]<=cap)
        profit1 = cost[i] + func(i+1, w+weight[i]); /// If ith product is taken

    profit2 = func(i+1, w);                         /// If ith product is not taken

    dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout<<"Please Enter the number of product: ";
    cin>>n;
    cout<<"Now Enter product weight and cost:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>cost[i];
    cout<<"Enter box capacity: ";
    cin>>cap;

    cout<<"Maximum Profit is : "<<func(1, 0)<<endl;

    return 0;
}
