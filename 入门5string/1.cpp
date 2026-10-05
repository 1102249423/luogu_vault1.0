#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);//🦖注意：如果用cin >> s，只能读取到第一个空格前的内容，而getline可以读取整行，这是这段代码能处理带空格字符串的关键。
    for(int i=0;i<s.size();i++)//🦖s.size()string 是一个类（class），而 size() 是这个类中预先定义好的成员函数
        if(s[i]>='a' && s[i]<='z')
            s[i]-='a'-'A';
    cout<<s;
    return 0;
}
