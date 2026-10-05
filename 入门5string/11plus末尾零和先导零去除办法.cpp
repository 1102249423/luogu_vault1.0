//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//    int flag;
//    int cnt;
//    int j;
//    string s;
//    cin>>s;//这个我们校长都能看得懂的输入~ 确实= =
//    for(int i=0;s[i];i++){//st.length()为读取字符串长度的函数，
//        if(s[i]=='.'){
//            flag=2;
//            cnt=i;
//        }else if(s[i]=='/'){
//            flag=3;
//            cnt=i;
//        }else if(s[i]=='%'){
//            flag=4;
//            cnt=i;
//        }else{
//            flag=1;
//        }
//    }
//    //🦖跃0需要学习
//    while(s[j]=='0'&&j>0)
//        j--;//去除多余前导0；
//    if(flag==1){//zheng
//        for(int i=s.length();i>=0;i--){
//            if(s[i]==0&&flag_zero==0){
//                cout<<s[i];
//            }
//            cout<<s[i];
//        }
//    }else if(flag==2){//xiao
//
//    }else if(flag==3){//fen
//
//    }else if(flag==4){//baifen
//
//    }
//    return 0;//愉快地结束程序~~~~
//}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    char p=0;//放符号
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9') cnt++;//记录第一个数长度
        else    //遇到符号，记录，跳出
        {
            p=s[i];
            break;
        }
    }
    int x=cnt;//记下第一个数末后一个的位置，也就是符号的位置，如果是分数或小数就要用
    cnt--;
    while(s[cnt]=='0'&&cnt>0) cnt--;//去除多余前导0；
    for(int i=cnt;i>=0;i--)//输出第一个数
        cout<<s[i];
    if(p==0)
        return 0;//无符号return 0
    else if(p=='%') {
        cout<<p;return 0;
    }
    else
        cout<<p;//其他继续
    int m=s.size()-1;
    while(s[x+1]=='0'&&x<m-1) //🦖去除末尾0
        x++;
    while(s[m]=='0'&&m>x+1) //🦖去除多余前导0
        m--;
    for(int i=m;i>x;i--)//输出第二个数
        cout<<s[i];
    return 0;
}

