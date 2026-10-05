#include <bits/stdc++.h>
using namespace std;
int a,b,c;//输入的倍数关系
int a1,b1,c1;//应当生成的数据
int google[12];//存放所有0-9的数字用来判断是不是都有了；
int flag=1;//判断是否合法
int count0=0;//计算几种类型情况
//不是去取数，而是从小到大直接枚举
int main(){
    cin>>a>>b>>c;
    for (int bs = 1; bs*3<999; ++bs) {
        flag=0;
        a1=bs*a;
        b1=bs*b;
        c1=bs*c;
        if (b1>999||c1>999)
            break;
        // for (int i = 1; i <=3; ++i) {
        //     google[a1%10]++;
        //     a1/=10;
        // }
        // for (int i = 1; i <=3; ++i) {
        //     google[a1%10]++;
        //     a1/=10;
        // }
        // for (int i = 1; i <=3; ++i) {
        //     google[a1%10]++;
        //     a1/=10;
        // }

        for (int i = 1; i <= 3; ++i)
        {
            google[a1 % 10]++;
            a1 /= 10;
            google[b1 % 10]++;
            b1 /= 10;
            google[c1 % 10]++;
            c1 /= 10;
        }
        for (int i = 1; i <= 9; ++i) {
            if (google[i]!=1) {
                flag=1;
                break;
            }
        }
        for (int i = 1; i <= 9; ++i) {
            google[i]=0;
        }
        if (flag==0||(!flag)) {
            cout<<bs*a<<" "
            <<bs*b<<" "
            <<bs*c<<" "<<endl;
            count0++;
        }
        // else {
        //     flag=0;
        // }
    }
    if (count0==0) {
        cout<<"No!!!";
    }



    return 0;
}