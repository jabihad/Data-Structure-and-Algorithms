#include<bits/stdc++.h>
using namespace std;

int dp[12345][12345];
string x, y, ans;
bool visited[12345][12345];
int lcs(int i,int j)
{
    int ans = 0, val1, val2;
    if(x[i]=='\0' || y[j]=='\0')
        return 0;
    if(visited[i][j])
        return dp[i][j];
    if(x[i]==y[j])
        ans = 1+lcs(i+1,j+1);
    else
    {
        val1 = lcs(i,j+1);
        val2 = lcs(i+1,j);
        ans = max(val1,val2);
    }
    visited[i][j]=1;
    dp[i][j] = ans;
    return dp[i][j];

}
void print(int i,int j)
{
    if(x[i]=='\0'||y[j]=='\0')
    {
        cout<<ans;
        return;
    }
    if(x[i]==y[j])
    {
        ans += x[i];
        print(i+1,j+1);
    }
    else if(dp[i][j+1]>=dp[i+1][j])
        print(i,j+1);
    else
        print(i+1,j);
}
int main()
{
    int l;
    printf("Please Enter the string: \n");
    cin>>x>>y;
    l = lcs(0,0);
    print(0,0);
    printf("\n");
    return 0;
}

