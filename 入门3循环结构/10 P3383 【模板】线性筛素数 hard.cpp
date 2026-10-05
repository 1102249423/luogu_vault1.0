#include <bits/stdc++.h>
using namespace std;
//布尔数组，标记某个数是否为素数，1 代表是素数，0 代表不是。数组大小 100000010 表示最多能筛到 1 亿。
bool isPrime[100000010];
//整型数组，按顺序存储筛选出的素数（比如 Prime[1]=2，Prime[2]=3，Prime[3]=5...）。数组大小 6000010 是因为 1 亿以内的素数约有 5761455 个，预留足够空间。
//cnt是质数的计数（同时作为Prime数组的下标）
int Prime[6000010],cnt=0;
void GetPrime(int n){
    memset(isPrime, 1, sizeof(isPrime));//🦖以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0;//1不是素数

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            Prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&& i*Prime[j]<=n;j++){
            isPrime[i*Prime[j]] = 0;//筛选出i*Prime[j]的因子。
            //if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
               // break; //保证每个合数只被它的最小质因数筛掉一次，从而实现 O(n) 的线性时间复杂度。
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);//先读入 n（筛素数的上限）和 q（查询次数）；
    GetPrime(n);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", Prime[k]);
    }
    return 0;
}