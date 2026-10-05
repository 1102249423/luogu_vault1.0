// #include <bits/stdc++.h>
// using namespace std;
// int n,k;
// int res[100];
// int vis[100];//全排列需要分析他是不是用过了。
// void dfs(int step,int last){
//     if (step>k) {
//         for (int i = 1; i <=k; ++i) {
//             cout<<setw(3)<<res[i];
//             // printf("%2d",res[i]);
//         }
//         cout<<endl;
//         return;
//     }
//     for (int i =last+1; i <=n; ++i) {
//         res[step]=i;
//         dfs(step+1,i);
//     }
// }
//
//
// int main(){
//     cin>>n>>k;
//     dfs(1,0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n,k;
int res[100];
int vis[100];//全排列需要分析他是不是用过了。
void dfs(int step){
    if (step>k) {
        for (int i = 1; i <=k; ++i) {
            cout<<setw(3)<<res[i];
            // printf("%2d",res[i]);
        }
        cout<<endl;
        return;
    }
    for (int i =res[step-1]+1; i <=n; ++i) {//step 代表：现在我们要填第 step 个位置。所以
        res[step]=i;
        dfs(step+1);
    }
}


int main(){
    cin>>n>>k;
    dfs(1);
    return 0;
}