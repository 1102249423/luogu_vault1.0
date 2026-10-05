//good way🦖
//string s;
//while (cin >> s) {
//
//}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string c;
    int cnt=0;
    //cin>>s;
    //getchar();  // 🦖C语言标准库函数，用于从标准输入读取一个字符。读取并丢弃换行符
    //cin.ignore();  // 🦖忽略一个字符（换行符），等价于cin.ignore(1, EOF);
    //cin.ignore(1, EOF);//🦖End Of File（文件结束符）
    //cin.ignore(1024, '\n');  // 🦖忽略最多1024字符直到换行符
    getline(cin,c);
    for(int i=0;c[i];i++){//🦖字符串读完的高级写法
        if(c[i]=='a'||c[i]=='d'||c[i]=='g'||c[i]=='j'||c[i]=='m'||c[i]=='p'||c[i]=='t'||c[i]=='w'){
            cnt+=1;
        }else if(c[i]=='b'||c[i]=='e'||c[i]=='h'||c[i]=='k'||c[i]=='n'||c[i]=='q'||c[i]=='u'||c[i]=='x'){
            cnt+=2;
        }else if(c[i]=='c'||c[i]=='f'||c[i]=='i'||c[i]=='l'||c[i]=='o'||c[i]=='r'||c[i]=='v'||c[i]=='y'){
            cnt+=3;
        }else if(c[i]=='s'||c[i]=='z'){
            cnt+=4;
        }else if(c[i]==' '){
            cnt+=1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
