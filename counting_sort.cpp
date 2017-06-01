#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

int Count[MAX], res[MAX], lo, hi;

void counting_sort()
{
    int i, j, k;
    for(i=lo,k = 0; i<=hi; i++)
    {
        for(j=1; j<=Count[i]; j++)
        {
            res[k++] = i;
        }
    }
    for(i=0; i<k; i++)
        printf("%d ",res[i]);
    printf("\n");
}
int main()
{
    int i, j, x, n;
    printf("Please Enter the number of elements you want to sort: ");
    scanf("%d",&n);
    printf("\nNow Enter the elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        Count[x]++;
        lo = min(lo,x);
        hi = max(hi,x);
    }
    printf("\nAfter Sorting\n\n");
    counting_sort();

    return 0;
}

