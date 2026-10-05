#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        cout<<(char)((s[i]-'a'+n)%26+'a');//🦖
    return 0;
}
