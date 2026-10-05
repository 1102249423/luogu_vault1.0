#include<bits/stdc++.h>
using namespace std;
int n,a[200];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);//排序
    n = unique(a + 1,a + n + 1) - (a + 1);//去重，并把去重后的元素个数记为 n
    printf("%d\n",n);//输出去重后的元素个数
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]);//输出去重后的元素
    printf("\n");
    return 0;
}
