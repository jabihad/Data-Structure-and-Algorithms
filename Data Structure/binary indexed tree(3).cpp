/// How range update, range query BIT works.
/*
Similar to Range Update - Point query, we maintain a BIT (say B1)
- Add v to [a..b] --> Update(a,v) and Update(b+1,-v) on the BIT B1
- Query(p) on B1 now gives the correct value of A[p]

The answer we want is ( Sum(0..b) - Sum(0..a-1) ), so lets design Sum(0..p). The thing with BIT is,
if you design it to work for one update ( which is easy to imagine ) and all possible queries on that
one update, mostly it should work for multiple updates ;)

Lets consider just one update : Add v to [a..b], rest all are 0

Now, consider Sum(0..p) for all possible p

1. 0 <= p <  a : 0
2. a <= p <= b : v * ( p - (a-1) )
3. b <  p <  n : v * ( b - (a-1) )

This suggests that, for a index p, if we have (v * p) we can get the Sum(0..p) by subtracting X from it

1. 0 <= p <  a : v = 0, X = 0
2. a <= p <= b : (v*p) - (v*(a-1)), X = v*(a-1)
3. b <  p <  n : v = 0, X = - v*b + v*(a-1)

So, we need to maintain something else too, to get that extra X factor and that should give
0 for p < a, v*(a-1) for p in [a..b], -v*b+v(a-1) for p > b.
Does this ring something ;) ? hoho ! one more BIT for keeping this X factor.

We need to maintain another BIT (say B2)
- Add v to [a..b] --> Update(a,v*(a-1)) and Update(b+1,-v*b) on the BIT B2
- Query(p) on B2 now gives the extra sum that should be subtracted from A[p]*p

*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll tree1[100005], tree2[100005];
int n;
ll query(ll* ft, int idx)
{
	ll sum = 0;
	while(idx>0){
        sum += ft[idx];
        idx -= idx & (-idx);
	}
	return sum;
}
ll range_query(int i, int j)
{
    ll q1, q2;
    q1 = query(tree1, i-1) * (i-1) - query(tree2, i-1);
    q2 = query(tree1, j) * j - query(tree2, j);

    return q2-q1;
}
void update(ll* ft, int idx, ll v)
{
	while(idx<=n){
        ft[idx] += v;
        idx += idx & (-idx);
	}
}
void range_update(int i, int j, ll v)	{
	update(tree1, i, v);
	update(tree1, j + 1, -v);
	update(tree2, i, v * (i - 1));
	update(tree2, j + 1, -v * j);
}

int main()  {
	int i, j, k, t, q, x, y, cmd;
    ll v;

    cout<<"Enter the number of test case: ";
	scanf("%d", &t);
	for(i=1;i<=t;i++){

        cout<<"Enter the array size and number of queries: ";
        cin>>n>>q;

		memset(tree1, 0, sizeof tree1);
		memset(tree2, 0, sizeof tree2);

        cout<<"Case "<<i<<endl;

		while (q--)	{
            cout<< "If you want to update array enter 0"<<endl;
            cout<< "If you want to query the array enter 1"<<endl;
			cin>>cmd;
			if(cmd == 0){
                cout<<"Enter the range and value you want to add: ";
                cin>>x>>y>>v;  /// 1-based index
                range_update(x, y, v);
			}
			else{
                cout<<"Enter the range which value you want to query: ";
                cin>>x>>y;
                cout<<"The sum of value from index "<<x<<" to "<<y<<" is "<<range_query(x, y)<<endl;
			}

		}
	}
    return 0;
}
