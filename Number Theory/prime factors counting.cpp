#include<bits/stdc++.h>
using namespace std;

bool mark[5000100];
int cnt[5000100];
void sieve()
{
    int i, j, temp, n = 5000000;
    for(i=2;i<=n;i++){
        if(!mark[i]){
            cnt[i] = 1;
            for(j=2*i;j<=n;j+=i){
                mark[j] = 1;
                temp = j;
                while(temp>1 && temp%i==0){
                    cnt[j]++;
                    temp /= i;
                }
            }
        }
        cnt[i] += cnt[i-1];             /// Cumulative sum
    }
}
int main()
{
    sieve();
    int a, b, n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){

        scanf("%d%d", &a, &b);          /// primefactor(42) = primefactor(6) + primefactor(7)
                                        /// primefactor(x) =  primefactor(a) + primefactor(x/a)
        printf("%d\n", cnt[a]-cnt[b]);  /// Total Prime factor of a!/b! = (b+1) * (b+2) * ....* (a-1) * (a) = cnt[a] - cnt[b]
    }
    return 0;
}
