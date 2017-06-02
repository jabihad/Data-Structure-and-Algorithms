#include<bits/stdc++.h>
using namespace std;

int a[1000006], b[1000006];
int main()
{
    int i, j, n, ans = 0, low, high, m;

    printf("Please Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of 1st array : ");

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("\nEnter the elements of 2nd array : ");
    for(i=0; i<n; i++)
        scanf("%d",&b[i]);

    printf("\nEnter the number which you want to match : ");
    scanf("%d",&m);

    /// two pointer starts

    low = 0;
    high = n-1;

    while(low < n)
    {
        while(a[low] + b[high] > m && high > 0)high--;
        if(a[low] + b[high] == m)ans++;
        low++;
    }
    printf("\nThere are %d ways to make %d from the summation of elements of two array\n",ans, m);

    return 0;
}
