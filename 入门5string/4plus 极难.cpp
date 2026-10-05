#include <bits/stdc++.h>
using namespace std;
int main(){
    char a;
    int n,c,d;
    char s[100],b[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        if(b[0]>='a'&&b[0]<='z'){
            a=b[0];
            cin>>c>>d;
        }else{
            //🦖从字符串str中按照指定格式format读取数据，并将结果存储到对应的变量中。它是scanf的字符串版本，scanf从标准输入读取，而sscanf从给定字符串读取。
            //从字符串b读取一个正数2存入c
            sscanf(b,"%d",&c);//这个
            cin>>d;
        }
        memset(s,0,sizeof(s));//🦖清空原有的字符串，防止长度判断错误。0和 '\0'在数值上完全相等，在memset中可以互换使用
        if(a=='a')
            //🦖sprintf：将格式化的数据写入字符串str。它是printf的字符串版本，printf输出到标准输出，而sprintf输出到指定字符数组。
            //将表达式结果如3+2存入s.
            sprintf(s,"%d+%d=%d",c,d,c+d);
        else if(a=='b')
            sprintf(s,"%d-%d=%d",c,d,c-d);
        else if(a=='c')
            sprintf(s,"%d*%d=%d",c,d,c*d);
        cout<<s<<endl<<strlen(s)<<endl;//输出字符串和字符串长度
    }
    return 0;
}









