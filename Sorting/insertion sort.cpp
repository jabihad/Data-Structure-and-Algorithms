#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int num[MAX], n;

void insertion_sort()
{
    int i, j, x;
    for(i=1; i<n; i++)
    {
        x = num[i];
        j = i-1;
        while(j>=0 && num[j]>x)
        {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = x;
    }
}
int main()
{
    int i, j;
    printf("Please Enter the number of elements you want to sort: ");
    scanf("%d",&n);
    printf("\nNow Enter the elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&num[i]);

    insertion_sort();

    printf("\nAfter Sorting\n\n");
    for(i=0; i<n; i++)
        printf("%d ",num[i]);
    printf("\n");

    return 0;
}
