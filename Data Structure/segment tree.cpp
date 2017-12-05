#include<bits/stdc++.h>
using namespace std;
#define mx 100050

int ara[mx];
int tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = ara[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; /// out of range
    if (b >= i && e <= j)
        return tree[node]; /// relevant segment
    int Left = node * 2;  ///  have to break
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; /// sum of left and right
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; /// out of range
    if (b >= i && e <= i) { /// relevant segment
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; /// have to break;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    int i, j, n, pos, val, sum=0;

    cout<<"Please Enter the number of elements: ";
    cin >> n;

    cout<<"Now Enter the elements: ";
    for(i=1;i<=n;i++)
        cin>> ara[i];

    init(1, 1, n);

    cout<<"Enter the position which value you want to change: ";
    cin>>pos;

    cout<<"Now Enter the value: ";
    cin>>val;

    update(1, 1, n, pos, val);

    cout<<"Enter the range ";
    cin>>i>>j;

    sum = query(1, 1, n, i, j);

    cout <<"Sum of array from index "<<i<<" to "<<j<<" is "<<sum<< endl;

    return 0;
}
