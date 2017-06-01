#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int num[MAX], n;

void selection_sort()
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(num[i]>num[j])
                swap(num[i],num[j]);
        }
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

    selection_sort();

    printf("\nAfter Sorting\n\n");
    for(i=0; i<n; i++)
        printf("%d ",num[i]);
    printf("\n");

    return 0;
}

