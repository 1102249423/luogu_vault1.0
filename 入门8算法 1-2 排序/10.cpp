#include <bits/stdc++.h>
using namespace std;
int n,m;
struct wdnmd {
    int ID;
    int score;
}a[114511];
bool compare1(wdnmd x,wdnmd y) {
    if (x.score!=y.score)
        return x.score>y.score;
    return x.ID<y.ID;
}
int cnt=0;

int main() {
}

//🦖第二个数字不能直接输出 k，要统计所有分数≥分数线的总人数（样例 k=4，但实际 5 人进面）
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i].ID>>a[i].score;
    }
    sort(a+1,a+n+1,compare1);
    int k=floor(m*1.5);
    int line=a[k].score;
    //cout<<line<<" "<<k<<endl;
    for (int i=1;i<=n;i++) {
        if (a[i].score>=line) {
            //cout<<a[i].ID<<" ";
            //cout<<a[i].score<<endl;
            cnt++;
        }
    }
    cout<<line<<" "<<cnt<<endl;
    for (int i=1;i<=n;i++) {
        if (a[i].score>=line) {
            cout<<a[i].ID<<" ";
            cout<<a[i].score<<endl;
        }
    }
    return 0;

}