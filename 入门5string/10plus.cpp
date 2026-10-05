#include<bits/stdc++.h>
using namespace std;
int main() {
    int boy=0,girl=0;
    string st;
    cin>>st;//这个我们校长都能看得懂的输入~ 确实= =
    for(int i=0;st[i];i++){//st.length()为读取字符串长度的函数，
        if (st[i]=='b'||st[i+1]=='o'||st[i+2]=='y')//判断连着的三个字母是否为b、o、y
            boy++;//boy计数器加一
        if (st[i]=='g'||st[i+1]=='i'||st[i+2]=='r'||st[i+3]=='l')//判断连着的三个字母是否为g、i、r、l
            girl++;//girl计数器加一
    }
    cout<<boy<<endl;//输出boy的个数  换行~
    cout<<girl<<endl;//输出girl的个数
    return 0;//愉快地结束程序~~~~
}
