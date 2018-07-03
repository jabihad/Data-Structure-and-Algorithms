#include<bits/stdc++.h>
using namespace std;

int mat[100][100], dp[100][100];
int r, c;
int call(int i, int j)
{
    if(i>=0 && i<r and j>=0 && j<c){ /// If inside array
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=INT_MIN;
        /// Moving to three default direction, also add current cell's point
        res = max(res, call(i+1, j) + mat[i][j]);
        res = max(res, call(i+1, j-1) + mat[i][j]);
        res = max(res, call(i+1, j+1) + mat[i][j]);
        return dp[i][j] = res;
    }
    else
        return 0;  /// If outside array
}

int main()
{
    int res=0;
    memset(dp, -1, sizeof(dp));
    cout<<"Please Enter Matrix size: ";
    cin>>r>>c;
    cout<<"Now Enter Matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    res = call(0, 0);
    cout<<"Maximum Point is: "<<res<<endl;


 return 0;
}
