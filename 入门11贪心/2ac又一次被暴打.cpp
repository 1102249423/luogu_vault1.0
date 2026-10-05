//那我每次的走法就等于=上一格的方案数+上上格的方案数咯，这就推出了方程：
//f[i]=f[i−1]+f[i−2]
#include<bits/stdc++.h>
#define N 250//2000位够了，250*8
using namespace std;
int  f[3][N+10],g;//1只用前三个数进行复用2f【0】【0】-f【0】【N】存放一个大的数据
int n;
int main()
{
    f[0][N]=1;
    f[1][N]=1;
    scanf("%d",&n);
    if(n == 0) {
        puts("0");
        return 0;
    }//0要特判
    for(int i=2;i<=n;i++)//i 代表当前要计算第 i+1 项斐波那契数
        for(int j=N;j>0;j--)
        {
            f[i%3][j]=(f[(i+1)%3][j]+f[(i+2)%3][j]+g)%100000000;
            g=(f[(i+1)%3][j]+f[(i+2)%3][j]+g)/100000000;//8个0，别漏了
        }
    int j=1;
    while((f[n%3][j]==0)&&(j<N))
        j++;//处理前导0
    for(int i=j;i<=N;i++)
    {
        if(i!=j){//不是最高位不用补0.内存中：f[x][i] = 123，仅此而已，没有 00000123。
            if(f[n%3][i]<1e7) putchar(48);
            if(f[n%3][i]<1e6) putchar(48);
            if(f[n%3][i]<1e5) putchar(48);
            if(f[n%3][i]<1e4) putchar(48);
            if(f[n%3][i]<1e3) putchar(48);
            if(f[n%3][i]<1e2) putchar(48);
            if(f[n%3][i]<1e1) putchar(48);
        }//补足前导0
        printf("%d",f[n%3][i]);//输出
    }
}
