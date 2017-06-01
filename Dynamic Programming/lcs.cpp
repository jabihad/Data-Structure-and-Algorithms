#include<bits/stdc++.h>
#define mx 6789
using namespace std;

int b[mx][mx], c[mx][mx];
void lcs(string x,string y)
{
    int i, j, m, n;
    m = x.size();
    n = y.size();
    for(i=0; i<=m; i++)
        c[i][0] = 0;
    for(j=0; j<=n; j++)
        c[0][j] = 0;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}
void print(string x,int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]==1)
    {
        print(x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==2)
        print(x,i-1,j);
    else
        print(x,i,j-1);
}
int main()
{
    int i, j, k;
    string x, y;

    printf("Please Enter the 1st string: \n");
    cin>>x;

    printf("Please Enter the 2nd string: \n");
    cin>>y;

    lcs(x,y);

    printf("\nThe longest common subsequence is: ");
    print(x,x.size(),y.size());

    printf("\n");
    return 0;
}

