#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<int>res;
int n, ara[6789];
void sliding_rmq(int m)
{
    deque<pii> dq;                                 /// 1st element of dq is ara value, 2nd element is ara index

                                                   /// dq is considered from left to right. As a result:

    for(int i=0;i<n;i++){                          /// left is called as front
                                                   /// right is called as back

        while(!dq.empty() && dq[0].first>=ara[i])  /// dq[0].first and dq.front().first is same
            dq.pop_front();                        /// pop out the leftmost element of dq which is greater than new value

        dq.push_front(pii(ara[i], i));             /// push the new value with its index in dq

        while(!dq.empty() && dq.back().second<=i-m)/// popping the out of range value
            dq.pop_back();

        if(i>=m-1){                                /// We got a m size range
            res.push_back(dq.back().first);        /// insert the rightmost (always smallest) element of DQ in res
        }
    }

}

int main()
{
    int i, j, k, m;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Now enter the elements: ";
    for(i=0;i<n;i++)
        cin>>ara[i];

    cout<<"Enter sub array size: ";
    cin>>m;

    sliding_rmq(m);
    for(i=0;i<res.size();i++){
        cout<<"Smallest element from index "<<i<<" to "<<i+m-1<<" is: ";
        cout<<res[i]<<endl;
    }

return 0;
}

