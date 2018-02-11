#include<bits/stdc++.h>
using namespace std;

void match(string s, string pattern)
{
    int i, j, k, l, l_s, l_p, flag=0;

    l_s = s.size();
    l_p = pattern.size();
    l =  l_s - l_p + 1;
    for(i=0; i<l; i++)
    {
        if(s[i]==pattern[0])
        {
            for(j=i+1, k=1; k<l_p; j++,k++)
            {
                if(s[j] != pattern[k])
                    break;
            }
            if(k == l_p)
            {
                flag = 1;
                printf("Pattern is found between index %d to %d\n",i, i+l_p-1);
                break;
            }
        }
    }
    if(flag == 0)
        printf("Pattern is not found in the string\n");
}
int main()
{
    string a, b;

    printf("Please Enter the string and pattern to match in the string:\n");

    cin>>a>>b;

    match(a, b);

    return 0;
}
