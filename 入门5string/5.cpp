#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    char c;
    if(cin>>c)ans++; //cin自动去除空格换行
    if(cin>>c)ans++; //cin在读不到数据时返回0
    if(cin>>c)ans++;
    if(cin>>c)ans++;
    if(cin>>c)ans++;
    cout<<ans;
}
