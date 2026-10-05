#include <bits/stdc++.h>
using namespace std;
int  n;
int res[100];//数据
int cnt=1;
//next_permutation()这个函数具体的使用你要自己研究
int main(){
    cin>>n;
    for (int i = 1; i <=n; ++i) {
        res[i]=i;
        cnt*=i;
    }
    //控制反转次数
    for (int i = 1; i <= cnt; ++i) {
        //控制全部输出
        for (int j = 1;j <=n; ++j) {
            cout<<setw(5)<<res[j];
        }
        next_permutation(res+1,res+n+1);
        cout<<endl;
    }
    return 0;
}

// next_permutation 有返回值：
// 成功生成下一个更大排列 → 返回 true
// 当前已经是最大排列（降序），没有下一个 → 返回 false
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int res[100];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        res[i]=i;
    do{
        //打印当前排列
        for (int j = 1;j <=n; ++j) {
            cout<<setw(5)<<res[j];
        }
        cout<<endl;
    }while(next_permutation(res+1,res+n+1));
    return 0;
}
 */
