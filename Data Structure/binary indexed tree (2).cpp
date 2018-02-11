/// How range update , point query BIT works
/*
Although not something you see every now and then, but it's readily doable. Now you are required to update v over the range [a, b] and the query is performed on a single index x. So now you call update twice, first add v at index a, then remove v for indices larger than b, which is: Update(a, v); Update(b+1, -v); And for query, you simply call Query(x). Now to see why this works, the following reasoning can be made:

Lets consider, initially you have everything 0. So Query(x) will return 0, no matter what index you call it with. Suppose you have called Update(a, v) and Update(b+1, -v). Now what will happen if you call Query(x)? Three cases can arise:
1. if x < a, the query is not affected by the updates. So you get correct result.
2. if x > b, x will be affected by the update(a, v) since x ≥ a, and update(b+1, -v) since x ≥ b+1, therefore, v-v=0 so everything cancels out. Again, you get the correct result.
3. a ≤ x ≤ b. x is only affected by update(a, v), but not update(b+1, -v), therefore, Query(x)'s value is increased by v, and it will return the correct result.
*/
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
void range_update(int a, int b, int value)
{
    update(a, value);
    update(b+1, -value);
}
int main()
{
    int t, i, j, a, b, u, q, v, idx;
    cout<<"Enter the number of test: ";
    cin>>n;
    while(t--){

        cout<<"Enter the array size: ";
        cin>>n;

        memset(tree, 0, sizeof(tree));  /// array must be initialized to 0 in range update point query

        cout<<"Enter the number of update: ";
        cin>>u;
        cout<<"Enter the range and value you want to add:\n";
                                      /// 1-based index
        for(i=1;i<=u;i++){
            cin>>a>>b>>v;
            range_update(a, b, v);

        }

        cout<<"Enter the number of query: ";
        cin>>q;

        cout<<"Enter the index which value you want to know:\n";
        for(i=1;i<=q;i++){
            cin>>idx;
            cout<<"Value in position "<< idx <<" is "<<query(idx)<<endl;
        }
    }
    return 0;
}
