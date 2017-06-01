#include<bits/stdc++.h>
using namespace std;

vector<int> divisors[100000];
void Divisors(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    int i, j, n;
    printf("Enter the number up to which you want to find all divisors: ");
    scanf("%d",&n);
    Divisors(n);
    for(i=1; i<=n; i++)
    {
        printf("Divisors of %d are : ",i);
        for(j=0; j<divisors[i].size(); j++)
        {
            printf("%d ",divisors[i][j]);
        }
        printf("\n");
    }

    return 0;
}

