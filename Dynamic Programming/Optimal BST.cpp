#include<bits/stdc++.h>
#define mx 6789
using namespace std;

double p[10000], q[10000], e[mx][mx], w[mx][mx];
int root[mx][mx];
void optimal_BST(int n)
{
    int i, j, l, r;
    double t;
    for(i=1; i<=n+1; i++)
    {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(l=1; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j = i+l-1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(r=i; r<=j; r++)
            {
                t = e[i][r-1] + e[r+1][j] + w[i][j];
                if(t < e[i][j])
                {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}
void print(int i,int j,int last)
{

    if (i > j && j<last)
    {
        printf("d%d is the left  child of k%d\n",j,last);
        return;
    }
    if (i > j && i>last)
    {
        printf("d%d is the right child of k%d\n",j,last);
        return;
    }
    if (last == 0)
        printf("k%d is the root\n",root[i][j]);
    else if (j < last)
        printf("k%d is the left  child of k%d\n",root[i][j],last);
    else
        printf("k%d is the right child of k%d\n",root[i][j],last);

    print(i, root[i][j] - 1, root[i][j]);
    print(root[i][j] + 1, j, root[i][j]);

}

int main()
{
    int i, j, k, n;
    printf("Please Enter the number of key in the tree: \n");
    scanf("%d",&n);
    printf("\nNow Enter the probability of the key:\n\n");
    for(i=1; i<=n; i++)
    {
        printf("Probability of key %d is: ",i);
        scanf("%lf",&p[i]);
    }
    printf("\nNow Enter the probability of the dummy key:\n\n");
    for(i=0; i<=n; i++)
    {
        printf("Probability of dummy key %d is: ",i);
        scanf("%lf",&q[i]);
    }
    optimal_BST(n);
    printf("\nThe expected cost of a search in the optimal Binary Search Tree is %.2lf\n\n",e[1][n]);
    print(1,n,0);

    return 0;
}
