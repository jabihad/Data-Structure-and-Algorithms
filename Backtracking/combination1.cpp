#include<bits/stdc++.h>
using namespace std;

int number[6789], n, k;
void combination(int at, int left)
{
    if(left > n - at + 1) return;
    if(at == n + 1)
    {
        for(int i=1; i<=k; i++)
            printf("%d ",number[i]);

        printf("\n");
        return;
    }
    if(left)
    {
        number[k - left + 1] = at;
        combination(at+1, left-1);
    }
    combination(at+1, left);
}
int main()
{
    printf("Enter the number : ");

    scanf("%d%d",&n, &k);

    printf("\nCombination of %d C %d  is  :\n",n, k);

    combination(1, k);

    return 0;
}
