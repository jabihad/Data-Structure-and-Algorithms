/// Coin number is unlimited
/// Check if we can make value n using the coin
#include<bits/stdc++.h>
using namespace std;

int possible[100000], coin[100000];
int main()
{
    int i, j, k, l, n;

    cout<<"Please Enter the number of coin: ";
    cin>>k;
    cout<<"Now Enter the coin value: ";
    for(i=1;i<=k;i++)
        cin>>coin[i];
    possible[0] = 1;

    cout<<"Enter the value which you want to make using coin: ";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(i>=coin[j])
                possible[i] |= possible[i-coin[j]];
        }
    }

    if(possible[n]==1)
        cout<<n<<" can be made using the coin"<<endl;
    else
        cout<<n<<" can not be made using the coin"<<endl;


    return 0;
}
