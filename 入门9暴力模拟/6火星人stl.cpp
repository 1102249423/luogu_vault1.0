#include <bits/stdc++.h>
using namespace std;
int N,M;
int a[114511];
int main(){
    cin>>N>>M;

    for (int i = 1; i <=N; ++i) {
        cin >> a[i];
    }
    for(int i=1;i<=M;++i)
        next_permutation(a+1,a+N+1);//🦖
    for(int i=1;i<=N;++i)
        printf("%d ",a[i]);
    return 0;

}
//快读
inline int read()
{
    int re=0, f=1; char ch=getchar();
    //第一步：跳过空格、换行
    while(ch<'0' || ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    //第二步：连续读取数字字符，拼成整数
    while(ch>='0' && ch<='9') {
        re=re*10+(ch-'0');
        ch=getchar();
    }
    return re*f;
}