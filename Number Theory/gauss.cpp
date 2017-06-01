#include<bits/stdc++.h>
using namespace std;

double mat[999][999],factor;

int main()
{
    int i,j,k,n,id,x,y;
    char ch;
    printf("Please Enter the number of equation: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Equation %d : ",i+1);
        for(j=0; j<n+1; j++)
        {
            scanf("%lf",&mat[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        id = i;
        for(j=i+1; j<n; j++)
            if(fabs(mat[j][i])>fabs(mat[id][i]))
                id = j;
        if(id!=i)
        {
            for(j=i; j<=n; j++)
                swap(mat[i][j],mat[id][j]);
        }
        for(j=0; j<n; j++)
            if(j!=i)
            {
                factor = mat[j][i]/mat[i][i];
                for(k=i; k<=n; k++)
                    mat[j][k] -= factor*mat[i][k];
            }
    }
    printf("Solution is :\n");
    for(i=0,j=3,ch='x',x=0,y=0; i<n; i++,ch++,x++,y++)
    {
        printf("%c = %.0lf\n",ch,mat[i][j]/mat[x][y]);
    }
    return 0;
}

