#include<bits/stdc++.h>
using namespace std;

///queen[i] = column number of queen at ith row
int queen[6789], res;
///arrays to mark if there is queen or not
int column[20], diagonal1[40], diagonal2[40];
/// call with nqueen(1, 8) for 8 queen problem
/// make sure column, diagonal1, diagonal2 are all 0 initialized
void nqueen(int at, int n)
{
    if(at == n + 1)
    {
        res++;
        printf("(row, column) = ");
        for(int i=1; i<=n; i++)
            printf("(%d, %d) ",i, queen[i]);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(column[i] || diagonal1[i+at] || diagonal2[n+i-at])
            continue;
        queen[at] = i;
        /// note that, i-at can be negative and we
        /// cant have array index negativr so we are
        /// adding offset n with this to make it positive
        column[i] = diagonal1[i+at] = diagonal2[n+i-at] = 1;
        nqueen(at+1, n);
        column[i] = diagonal1[i+at] = diagonal2[n+i-at] = 0;
    }
}
int main()
{
    nqueen(1,8);
    printf("\n%d\n",res);

}
