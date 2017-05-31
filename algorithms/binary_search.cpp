#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int num[MAX], n;

void binarysearch(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(x > num[mid])
        {
            lo = mid + 1;
        }
        else if(x < num[mid])
        {
            hi = mid - 1;
        }
        else if(x==num[mid])
        {
            printf("%d is found at position %d\n",x, mid);
            break;
        }
    }
    if(lo>hi)
        printf("%d is not found in the array\n",x);
}
int main()
{
    int i, j, x;
    printf("Enter the total number of elements in array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&num[i]);
    printf("Enter the number whom you want to find: ");
    scanf("%d",&x);
    binarysearch(x);

    return 0;
}
