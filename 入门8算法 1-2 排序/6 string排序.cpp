#include <bits/stdc++.h>
using namespace std;
int n;
int a[50];
struct wdnmd {
    string piaoshu;//🦖要通过string来比较
    int id;
}candidate[50];
bool comp(wdnmd x,wdnmd y) {
    if (x.piaoshu.size()!=y.piaoshu.size())
        return x.piaoshu.size() > y.piaoshu.size();
    if (x.piaoshu!=y.piaoshu)
        return x.piaoshu>y.piaoshu;//🦖string 可以是直接比较的
    return x.id < y.id; // 票数一样，编号小靠前
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>candidate[i].piaoshu;
        candidate[i].id=i;
    }
    sort(candidate+1,candidate+n+1,comp);

    cout<<candidate[1].id<<endl;
    cout<<candidate[1].piaoshu<<endl;
    return 0;
}