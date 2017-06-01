#include<bits/stdc++.h>
using namespace std;

int ara[1000006];
int main()
{
    int i, n, mx = -1, sum = 0;


    printf("Please Enter the number of elements in the array: ");

    scanf("%d",&n);

    printf("Now Enter the elements: \n");

    for(i=0; i<n; i++)
        scanf("%d",&ara[i]);

    for(i=0; i<n; i++)
    {
        sum += ara[i];
        if(sum < 0)
            sum = 0;
        mx = max(mx,sum);
    }
    printf("Summation of maximum subarrray is %d\n",mx);

    return 0;
}

