#include<bits/stdc++.h>
using namespace std;
int a[1200][1200];
int main()
{
    int n,i,j,k,s=1;
    cin>>n;
    a[0][0]=1;
    for(i=0;i<n;i++,s*=2)//递推n次，s：当前子矩阵大小，每次翻倍（1→2→4→8...），循环结束后执行 s*=2→ s=2
        for(j=0;j<s;j++)// 遍历行
            for(k=0;k<s;k++)// 遍历列
                a[j][k+s]=a[j+s][k]=a[j][k];
    for(i=s-1;i>=0;i--)//倒序输出
    {
        for(j=s-1;j>=0;j--)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

