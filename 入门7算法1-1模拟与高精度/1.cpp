//🦖char数组或者strings存放
#include<bits/stdc++.h>
using namespace std;
char C;
string S;
int n,A,B;
int main()
{
    //🦖其中 while(cin>>C) 这一语法利用了 cin 的特性，当 cin 没能读入到信息的时候，会返回 0，那么循环就会终止。
    while(cin>>C)
    {
        if(C=='E')break;
        S+=C;
    }
    /*这是 C++11 的范围for循环，语法糖，等价于：
     for(int idx = 0; idx < S.length(); idx++)
    {
        char i = S[idx];
    }
    */
    for(char i:S)
    {
        if(i=='W')A++;
        if(i=='L')B++;
        if(max(A,B)>=11&&abs(A-B)>=2)
        {
            cout<<A<<":"<<B<<endl;
            A=0,B=0;
        }
    }
    printf("%d:%d\n",A,B);
    A=B=0;
    puts("");//等价于 cout << "\n"; 或 cout << endl;
    for(char i:S)
    {
        if(i=='W')A++;
        if(i=='L')B++;
        if(max(A,B)>=21&&abs(A-B)>=2)
        {
            cout<<A<<":"<<B<<endl;
            A=0,B=0;
        }
    }
    printf("%d:%d\n",A,B);
    return 0;
}







