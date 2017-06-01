#include<bits/stdc++.h>
using namespace std;

int used[20000],number[20000];

void permutation(int at,int n)
{
    if(at==n+1)
    {
        for(int i=1; i<=n; i++)
            printf("%d ",number[i]);
        printf("\n");
        return;
    }
    for(int i=1; i<=n; i++)if(!used[i])
        {
            used[i] = 1;
            number[at] = i;
            permutation(at+1,n);
            used[i] = 0;
        }
}
int main()
{
    int a, b;

    printf("Enter the number : ");
    scanf("%d%d",&a, &b);
    printf("Permutation of %d to %d is :\n",a, b);
    permutation(a, b);

    return 0;
}
