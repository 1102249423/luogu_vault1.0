#include<bits/stdc++.h>
using namespace std;
string str;
string rep(string s)
{
    int t=0;
    for(int i=0;s[i];i++)
    {
        if(isdigit(s[i]))t=(t<<3)+(t<<1)+(s[i]^48);//🦖
        //t <<3：t 左移 3 位 = t *8
        // t <<1：t 左移 1 位 = t *2
        // t*8 + t*2 = t*10，实现十进制进位。
        // s[i]^48：字符转整数。字符'0'ASCII 码就是 48，等价s[i]-'0'
        else break;
    }
    string x="",//要重复的子串
    y="";//最后返回结果，重复拼接后的字符串。
    for(int i=s.size()-1;i>=0;i--)
    {
        if(isalpha(s[i]))x+=s[i];//🦖如果是大写字母，加到 x 末尾。
        else break;
    }
    reverse(x.begin(),x.end());//倒着读碰到数字停止然后反转
    while(t--)y+=x;//先检查是不是0再减1
    return y;
}
int main()
{
    cin>>str;
    while(true)
    {
        int l=-1,r=-1;
        for(int i=str.size()-1;i>=0;i--)
        {
            if(str[i]=='[')
            {
                l=i;
                break;
            }
        }
        if(l==-1)break;
        for(int i=l;str[i];i++)
        {
            if(str[i]==']')
            {
                r=i;
                break;
            }
        }
        string ns="";
        for(int i=l+1;i<r;i++)ns+=str[i];
        str=str.replace(l,r-l+1,rep(ns));
        //l：开始替换的位置（左括号下标）
        //r‑l+1：要删掉的字符总长度，把 [......]一整块全部删掉（包含[和]）
        //rep(ns)调用函数得到解压后的字符串，插入到 l 位置。
    }
    cout<<str;
    return 0;
}
