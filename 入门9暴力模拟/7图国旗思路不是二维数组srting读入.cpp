#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans=0x7fffffff,w[51],b[51],r[51];//🦖ans=0x7fffffff学习了int最大上限
string s;
// 计算当前这一行全部涂成字符c需要修改多少格
inline int check(char c){
    int tot=0;
    for(int i=0;i<m;++i)
        if(s[i]!=c)++tot;
    return tot;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s;
        // w[i]：前i行全部涂成白色一共需要改多少格（前缀和）
        w[i]=w[i-1]+check('W');
        // b[i]：前i行全部涂成蓝色一共需要改多少格
        b[i]=b[i-1]+check('B');
        // r[i]：前i行全部涂成红色一共需要改多少格
        r[i]=r[i-1]+check('R');
    }

    // 枚举分割线 i、j
    // 1~i：白；i+1~j：蓝；j+1~n：红
    for(int i=1;i<=n-2;++i)
        for(int j=i+1;j<=n-1;++j)
            ans=min(ans, w[i] + (b[j]-b[i]) + (r[n]-r[j]) );//🦖这个思路非常值得学习
    cout<<ans;
    return 0;
}