#include<bits/stdc++.h>
#define mx 6789
using namespace std;

int m[mx][mx], p[mx], s[mx][mx];
void matrix_chain_order(int n)
{
    int i, j, k, l, q;
    for(i=1; i<=n; i++)
        m[i][i] = 0;
    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void parens(int i,int j)
{
    if(i==j)
        printf("A%d ",i);
    else
    {
        printf("( ");
        parens(i,s[i][j]);
        parens(s[i][j]+1,j);
        printf(" )");
    }
}

int main()
{
    int i, j, k, n;
    printf("Please Enter the total number of matrix:\n");
    scanf("%d",&n);

    printf("Please Enter the dimension of matrix:\n");
    for(i=1; i<=n; i++)
        scanf("%d%d",&p[i-1],&p[i]);

    matrix_chain_order(n);

    printf("The minimum number of scalar multiplication is %d\n\n",m[1][n]);

    printf("Optimal Parenthesization is : ");
    parens(1,n);
    printf("\n");

    return 0;
}


