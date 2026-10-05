#include <bits/stdc++.h>
using namespace std;
int n;
int kind=0;//多少种类
int m1[10000][10];//🦖全部的结果
int m2[10];//临时存放数组
void peiliao(int total,int a){//total全部配料，a是当前配料
    if (a==10) {
        if (total==n) {
            for (int i=0;i<10;++i) {
                m1[kind][i]=m2[i];
            }
            kind++;
        }
    }
    else if (total>=n) return; //🦖剪zhi优化确实牛逼
    else {
        for (int i = 1; i <=3; ++i) {
            m2[a]=i;
            peiliao(total+i,a+1);//🦖精华所在
        }
    }

}
int main(){
    cin>>n;
    peiliao(0,0);
    cout<<kind<<endl;
    for (int i = 0; i < kind; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<m1[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}