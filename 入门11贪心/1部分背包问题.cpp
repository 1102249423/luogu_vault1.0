#include <bits/stdc++.h>
using namespace std;
struct Node {
    int w,v;//weight value
}a[110];

bool cmp(Node aa,Node bb) {
    return aa.v*bb.w>aa.w*bb.v;
}

int main() {
    int N,T;
    double ans=0;
    cin>>N>>T;
    for(int i=1;i<=N;++i) {
        cin>>a[i].w;
        cin>>a[i].v;
    }
    sort(a+1,a+N+1,cmp);//排序

    for(int i=1;i<=N;i++){//一次遍历
        if(a[i].w<=T) {
            ans+=a[i].v;
            T-=a[i].w;//够就全拿
        }else{//不够
            ans+=a[i].v*T*1.0/(a[i].w*1.0);//拿上能拿的部分，注意强转double
            break;//直接退出循环
        }
    }
    printf("%.2lf",ans);//保留2位小数
    return 0;//华丽结束




}



