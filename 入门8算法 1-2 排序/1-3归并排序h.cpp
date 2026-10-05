#include <bits/stdc++.h>//🦖分两组然后依次拿小的扔到新数组里面
using namespace std;
int n,m;
int a[2000000],b[2000000];
void merge_sort(int l,int r) {
    int mid=(l+r)/2;
    int q=l,h=mid+1,cnt=0;//从中间断开
    while (q<=mid && h<=r) {
        if (a[q]<=a[h]){
            cnt++;
            b[cnt]=a[q];
            q++;
        }else {
            cnt++;
            b[cnt]=a[h];
            h++;
        }
    }
    //左数组先走完，右数组还有剩余元素or右数组先走完，左数组还有剩余元素
    while (q<=mid) {
        cnt++;
        b[cnt]=a[q];
        q++;
    }
    while (h<=r) {
        cnt++;
        b[cnt]=a[h];
        h++;
    }
    for (int i = 1,j=l; i <=cnt; ++i,++j) {//cnt记录了多少个数
        a[j]=b[i];
    }
}
void m_sort(int l,int r) {
    if(l>=r) return;
    int mid=(l+r)/2;
    m_sort(l,mid);//走完他切到1个元素
    m_sort(mid+1,r);//  再往下递归它
    merge_sort(l,r);//最后合并
    return;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    m_sort(1,m);
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;
}