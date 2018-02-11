#include<bits/stdc++.h>
using namespace std;

int f[5678];
void kmp_preprocess(string pattern)
{
    f[0]=0;
    int j = 0, m;
    m = pattern.size();
    for(int i = 1; i < m; i++)
    {
        if(pattern[i]==pattern[j])
            f[i]=j+1,j++;
        else
        {
            while(j!=0)
            {
                j = f[j-1];
                if(pattern[i]==pattern[j])
                {
                    f[i] = j+1;
                    j++;
                    break;
                }
            }
        }
    }
}
bool kmp(string text, string pattern)
{
    int j = 0, n, m;
    n = text.size();
    m = pattern.size();
    for(int i = 0; i < n; i++)
    {
        if(text[i]==pattern[j])
        {
            if(j==m-1)
            {
                return true;
            }
            j++;
        }
        else
        {
            while(j!=0)
            {
                j = f[j-1];
                if(text[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return false;
}

int main()
{
    int chk=0;
    string pattern, text;

    cout<<"Please Enter the text: ";
    cin>>text;

    cout<<"Now Enter the pattern which you want to find in the text: ";
    cin>>pattern;

    kmp_preprocess(pattern);
    chk = kmp(text, pattern);

    if(chk)
        cout<<"Pattern Found\n";
    else
        cout<<"Pattern not Found\n";


    return 0;
}
