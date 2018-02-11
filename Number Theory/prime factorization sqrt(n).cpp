#include<bits/stdc++.h>
using namespace std;

void PrimeFactors(int n)
{
    while(n%2==0){
        cout<<2<<" ";
        n /= 2;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            cout<<i<<" ";
            n /= i;
        }
    }
    /// This condition is to handle the case when n
    /// is a prime number greater than 2
    if(n>2)
        cout<<n;
}
int main()
{
    int n;
    cout<<"Enter the number to print all prime factors of it: ";

    cin>>n;

    PrimeFactors(n);

    cout<<endl;

    return 0;
}
