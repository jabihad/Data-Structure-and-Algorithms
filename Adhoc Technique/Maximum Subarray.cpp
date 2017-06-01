#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c)
{
    return max(max(a,b), c);
}
int a[1000006];

int max_crossing_subarray(int low,int mid,int high)
{
    int left_sum = INT_MIN, sum = 0;
    for(int i=mid; i>=low; i--)
    {
        sum += a[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN ;
    for(int i=mid+1; i<=high; i++)
    {
        sum += a[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    return left_sum+right_sum;
}
int max_subarray(int low,int high)
{
    if(high==low)
        return a[low];

    int mid = (low+high)/2;

    return max(max_subarray(low,mid), max_subarray(mid+1,high), max_crossing_subarray(low,mid,high));
}

int main()
{
    int i, j, n, max_sum;
    printf("Please Enter the number of elements in the array: ");

    scanf("%d",&n);

    printf("Now Enter the elements: \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    max_sum = max_subarray(0,n-1);

    printf("Summation of maximum subarrray is %d\n",max_sum);

    return 0;
}

