#include <bits/stdc++.h>
using namespace std;
//typedef long long LL;
int main(){
    //c：用于存储要查找的单词
    //s：用于存储输入的句子
    string c,s;
    cin>>c;
    //getchar();  // 🦖C语言标准库函数，用于从标准输入读取一个字符。读取并丢弃换行符
    cin.ignore();  // 🦖忽略一个字符（换行符），等价于cin.ignore(1, EOF);
    //cin.ignore(1, EOF);//🦖End Of File（文件结束符）
    //cin.ignore(1024, '\n');  // 🦖忽略最多1024字符直到换行符
    getline(cin,s);
    c = ' '+c+' ';
    s = ' '+s+' ';
    for(int i=0;c[i];i++){//🦖字符串读完的高级写法
        c[i] = toupper(c[i]);
    }
    for(int i=0;s[i];i++){
        s[i] = toupper(s[i]);
    }
    int pos = s.find(c);
    int t = pos;
    if(pos==-1){
        cout<<-1;
        return 0;
    }
    int cnt = 0;
    while(pos!=-1){
        cnt++;
        pos = s.find(c,pos+1);
    }
    cout<<cnt<<' '<<t<<endl;
    return 0;
}
