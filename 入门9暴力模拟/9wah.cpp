
// 首先我认为你的十位、百位、千位的计算逻辑错误，这是第一点。要你的拆分方式确实有自己的思考过程，
// 但是。实现一个函数去统一的计算是最方便
#include <bits/stdc++.h>
using namespace std;
int huochai[10];
int n;
int a1,a2,b1,b2,c1,c2;
int cnt=0;
int cnt_all=0;
int main(){
    huochai[0]=6;
    huochai[1]=2;
    huochai[2]=5;
    huochai[3]=5;
    huochai[4]=4;
    huochai[5]=5;
    huochai[6]=6;
    huochai[7]=3;
    huochai[8]=7;
    huochai[9]=6;
    cin>>n;
    n-=4;
    for (int i = 0; i <=99; ++i) {
        for (int j = 0; j <=99; ++j) {
            for (int k = 0; k <=99; ++k) {
                if (i+j==k) {
                    cnt=0;
                    a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;//必须刷新
                    a1=i%10;
                    if ((i/10)%10!=0)
                        a2=(i/10)%10;

                    b1=j%10;
                    if ((j/10)%10!=0)
                        b2=(j/10)%10;

                    c1=k%10;
                    if ((k/10)%10!=0)
                        c2=(k/10)%10;

                    cnt+=huochai[a1]+huochai[b1]+huochai[c1];
                    if (a2>0) {
                        cnt+=huochai[a2];
                    }
                    if (b2>0) {
                        cnt+=huochai[b2];
                    }
                    if (c2>0) {
                        cnt+=huochai[c2];
                    }
                    if (cnt==n) {
                        cnt_all++;
                        //cout<<a2<<a1<<"+"<<b2<<b1<<"="<<c2<<c1<<endl;
                        //cout<<huochai[a2]<<huochai[a1]<<" "<<huochai[b2]<<huochai[b1]<<"="<<huochai[c2]<<huochai[c1]<<endl;
                    }
                }
            }
        }
    }
    cout<<cnt_all<<endl;
    return 0;
}