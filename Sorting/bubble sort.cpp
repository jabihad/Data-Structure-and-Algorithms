#include<bits/stdc++.h>
#define MAX 6789
using namespace std;

int num[MAX], n;

void bubble_sort()
{
    int i, j, temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(num[j+1]<num[j]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
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

    bubble_sort();

    printf("\nAfter Sorting\n\n");
    for(i=0; i<n; i++)
        printf("%d ",num[i]);
    printf("\n");

    return 0;
}

