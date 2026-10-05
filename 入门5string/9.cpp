#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[102];
int main()
{
    int n;
    string s;

    cin>>n>>s;
    //c++11 only
    //gets(a);//第一次读取行末换行符（实际忽略第一行的数字 n）.
    //gets(a);//第二次读取目标字符串.
    int ans=0;
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i]=='V' && s[i+1]=='K')
        {
            ans++;
            //并将这两个字符改为 X作为标记。防止后续重复计数，并确保第二轮扫描时不干扰.
            s[i]='X';
            s[i+1]='X';
        }
    }
    //find vv and kk
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i]!='X' && s[i]==s[i+1])
        {
            ans++;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

