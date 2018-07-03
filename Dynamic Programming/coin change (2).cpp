/// Coin number is unlimited
/// Check how many ways we can make value n using the coin
#include<bits/stdc++.h>
using namespace std;

int way[100000], coin[100000];
int main()
{
    int i, j, k, l, n;

    cout<<"Please Enter the number of coin: "; /// unique
    cin>>k;
    cout<<"Now Enter the coin value: ";
    for(i=1;i<=k;i++)
        cin>>coin[i];
    way[0] = 1;

    cout<<"Enter the value which you want to make using coin: ";
    cin>>n;

    /// Following will consider 1, 2 and 2, 1 as different way
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(i>=coin[j])
                way[i] += way[i-coin[j]];
        }
    }
    /*Following will consider 1, 2 and 2, 1 as same way
    for(i=1;i<=k;i++){
        for(j=coin[i];j<=n;j++)
            way[j] += way[j-coin[i]];
    }*/

    if(way[n]>=1)
        cout<<n<<" can be made in "<<way[n]<<" ways"<<endl;
    else
        cout<<n<<" can not be made using the coin"<<endl;


    return 0;
}
