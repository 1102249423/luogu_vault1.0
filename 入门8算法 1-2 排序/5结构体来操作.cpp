#include <bits/stdc++.h>
using namespace std;

struct xx {
    int yuwen;
    int shuxue;
    int yingyu;
    int zongfen;
    int bianhao;
}a[360];

int n;
//comp true x在y之前；
bool comp(xx x,xx y) {
    if (x.zongfen!=y.zongfen) {
        return x.zongfen>y.zongfen;
    }else if (x.yuwen!=y.yuwen) {
        return x.yuwen>y.yuwen;
    }else if (x.bianhao!=y.bianhao) {
        return x.bianhao<y.bianhao;
    }
}

// typedef struct TreeNode tree;
// struct TreeNode
// {
//     ElementType element;
//     Tree left;
//     Tree right;
// }T1[MaxTree], T2[MaxTree];

int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>> a[i].yuwen >> a[i].shuxue >> a[i].yingyu;
        a[i].bianhao=i;
        a[i].zongfen=a[i].yuwen+a[i].shuxue+a[i].yingyu;
    }
    //掌握精髓
    sort(a+1,a+n+1,comp);
    for (int i = 1; i <= 5; ++i) {
        cout<<a[i].bianhao<<" "<<a[i].zongfen<<endl;
        
    }
    return 0;
}