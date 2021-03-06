#include<bits/stdc++.h>
#define mx 101
using namespace std;

int a[mx];
void ins_heap(int n,int item)
{
    int ptr,par;
    n = n+1;
    ptr = n;
    while(ptr>1)
    {
        par = ptr/2;
        if(item <= a[par])
        {
            a[ptr] = item;
            return;
        }
        a[ptr] = a[par];
        ptr = par;
    }
    a[1] = item;
}
void del_heap(int n)
{
    int item, last, ptr, left, right;
    item = a[1];
    last = a[n];
    n = n-1;
    ptr = 1;
    left = 2;
    right = 3;
    while(right<=n)
    {
        if(last >= a[left] && last >= a[right])
        {
            a[ptr] = last;
            return;
        }
        if(a[right] <= a[left])
        {
            a[ptr] = a[left];
            ptr = left;
        }
        else
        {
            a[ptr] = a[right];
            ptr = right;
        }
        left = 2*ptr;
        right = left+1;
    }
    if(left==n && last<a[left])
    {
        a[left/2] = a[left];
        ptr = left;
    }
    a[ptr] = last;
}
void heapsort(int n)
{
    int i = n+1;
    while(i>1)
    {
        a[i] = a[1];
        del_heap(i-1);
        i--;
    }
}
int main()
{
    int i, n, item;
    printf("Please Enter the number of elment: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&item);
        ins_heap(i,item);
    }
    printf("\nAfter Sorting\n");
    heapsort(n);
    for(i=2; i<=n+1; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
