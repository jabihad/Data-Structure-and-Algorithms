#include<bits/stdc++.h>
using namespace std;

int f[1100000], cnt=0;
char pattern[1100000], text[1100000];
void kmp_preprocess()
{
    f[0] = 0;
    int i, j = 0;
    for(i=1; pattern[i]; i++){
        if(pattern[i] == pattern[j]){
            f[i] = j + 1;
            j++;
        }
        else{
            while(j!=0){
                j = f[j-1];
                if(pattern[i]==pattern[j]){
                    f[i] = j + 1;
                    j++;
                    break;
                }
            }
        }
    }
}
void kmp()
{
    int n, m, i, j=0;
    n = strlen(text);
    m = strlen(pattern);
    for(i=0; i<n; i++){
        if(text[i]==pattern[j]){
            if(j==m-1){
                cnt++;
                j = f[j];         /// text = aaaaa  pattern = aaa   result is 3
                                 ///  text = aaaaa  pattern = aaa   result will be 1 if we change j = 0
            }
            else
                j++;
        }
        else{
            while(j!=0){
                j = f[j-1];
                if(text[i]==pattern[j]){
                    j++;
                    break;
                }
            }
        }
    }
}
int main()
{
    int i, j, k, t;

    scanf("%d", &t);
    for(i=1;i<=t;i++){

        scanf("%s%s", text, pattern);
        cnt = 0;
        memset(f, 0, sizeof f);
        kmp_preprocess();
        kmp();
        printf("Case %d: %d\n", i, cnt);
    }
    return 0;
}
