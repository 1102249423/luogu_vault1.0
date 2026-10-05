#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans[1000005];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <=m ; ++i) {
        int id=0;
        for (int j = 1; j <=i; ++j) {
            id=j;
            if (a[i]<ans[j]) {
                break;
            }
        }
        for(int j=i;j>=id;j--)
        {
            ans[j+1]=ans[j];//把其他数往后移动一格
        }
        ans[id]=a[i];//最后把数放进去
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
