#include <bits/stdc++.h>
using namespace std;
#define mx 100050

int arr[mx];
struct info
{
    int prop, sum;
} tree[mx*3];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = 2 * node;
    int right = 2 * node +1 ;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, int newValue)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum += (e - b + 1) * newValue;
        tree[node].prop += newValue;
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, newValue);
    update(right, mid+1, e, i, j, newValue);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree[node].sum + carry * (e - b + 1);
    int left = node << 1;
    int right = (node << 1)+1;
    int mid = (b + e) >> 1;

    int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);

    return p1+p2;
}

int main()
{

    int n, a, b, x, y, sum, val, q;
    cout<<"Please Enter the size of array: ";
    cin>>n;

    cout<<"Now enter the array elements: ";
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    init(1, 1, n);

    cout<<"Please enter the range which you want to update: ";
    cin>>a>>b;

    cout<<"Enter the value which you want to add: ";
    cin>>val;

    update(1, 1, n, a, b, val);

    cout<<"Enter the number of query: ";
    cin>>q;
    for(int i=0; i<q; i++)
    {

        cout<<"Enter the query range: ";
        cin>>x>>y;

        sum = query(1, 1, n, x, y);

        cout<<"Sum of array from index "<<x<<" to "<<y<<" is: "<<sum<< endl;
    }

    return 0;
}
