#include<bits/stdc++.h>
using namespace std;

int number[6789], n, k;
void combination(int at, int last)
{
    if(at == k+1)
    {
        for(int i=1; i<=k; i++)
            printf("%d ",number[i]);
        printf("\n");
        return;
    }
    for(int i = last+1; i<=n-k+at; i++)
    {
        number[at] = i;
        combination(at+1, i);
    }
}
int main()
{
    printf("Enter the number : ");

    scanf("%d%d",&n, &k);

    printf("\nCombination of %d C %d  is  :\n",n, k);

    combination(1, 0);

    return 0;
}
