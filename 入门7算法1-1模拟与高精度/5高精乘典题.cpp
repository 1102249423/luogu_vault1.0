#include <bits/stdc++.h>
using namespace std;
char a1[10001],b1[10001];
int a[10001],b[10001],i,x,len,j,c[10001];
int main ()
{
    cin>>a1>>b1;
    int lena=strlen(a1);
    int lenb=strlen(b1);
    //反转后，数组索引1对应个位，2对应十位，以此类推，这样在计算时可以直接从索引1开始逐位处理。
    for(i=1;i<=lena;i++)
        a[i]=a1[lena-i]-'0';
    for(i=1;i<=lenb;i++)
        b[i]=b1[lenb-i]-'0';
    for(i=1;i<=lenb;i++)
        for(j=1;j<=lena;j++)
            //为什么是这个，值得学习P1303 A*B Problem 第一个题解张图片你可以看看
            c[i+j-1]+=a[j]*b[i];


    for(i=1;i<lena+lenb;i++)
        if(c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    len=lena+lenb;
    // 找到最高位（去掉前导0）
    while(c[len]==0&&len>1)len--;
    //再倒着输出
    for(i=len;i>=1;i--)cout<<c[i];
    return 0;
}
