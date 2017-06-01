#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int num[MAX], temp[MAX], n;

void mergesort(int lo,int hi)
{
    if(lo == hi)return;
    int mid = (lo+hi)/2;

    mergesort(lo,mid);
    mergesort(mid+1,hi);

    int i, j, k;
    for(i=lo,j=mid+1,k=lo; k<=hi; k++)
    {
        if(i==mid+1)
            temp[k] = num[j++];
        else if(j==hi+1)
            temp[k] = num[i++];
        else if(num[i]<num[j])
            temp[k] = num[i++];
        else
            temp[k] = num[j++];
    }
    for(k=lo; k<=hi; k++){
        num[k] = temp[k];
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

    mergesort(0,n-1);

    printf("\nAfter Sorting\n\n");
    for(i=0; i<n; i++)
        printf("%d ",num[i]);
    printf("\n");

    return 0;
}
