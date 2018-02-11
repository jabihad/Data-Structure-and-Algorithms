/// Point update, Range query
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll tree[10100], n;
ll query(int idx)
{
    ll sum=0;
    while(idx>0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int value)
{
    while(idx<=n){
        tree[idx] += value;
        idx += idx & (-idx);
    }
}
int main()
{
    int t, i, j, a, b, u, q, v, idx;
    cout<<"Enter the number of test: ";
    cin>>n;
    while(t--){

        cout<<"Enter the array size: ";
        cin>>n;

        memset(tree, 0, sizeof(tree));  /// array must be initialized to 0

        cout<<"Enter the number of update: ";
        cin>>u;

        cout<<"Enter the index and the value you want to add:\n";
        for(i=1;i<=u;i++){
            cin>>a>>v;                 /// 1-based index
            update(a, v);

        }

        cout<<"Enter the number of query: ";
        cin>>q;

        cout<<"Enter the range which value you want to know:\n";
        for(i=1;i<=q;i++){
            cin>>a>>b;
            cout<<"Value in range from "<< a <<" to "<<b<<" is "<<query(b)-query(a-1)<<endl;
        }
    }
    return 0;
}

