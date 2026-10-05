#include <bits/stdc++.h>
using namespace std;
//布尔数组，标记某个数是否为素数，1 代表是素数，0 代表不是。数组大小 100000010 表示最多能筛到 1 亿。
bool isPrime[100000];
//整型数组，按顺序存储筛选出的素数（比如 Prime[1]=2，Prime[2]=3，Prime[3]=5...）。数组大小 6000010 是因为 1 亿以内的素数约有 5761455 个，预留足够空间。
//cnt是质数的计数（同时作为Prime数组的下标）
int Prime[100000],cnt=0;
void GetPrime(int n){
    memset(isPrime, 1, sizeof(isPrime));//🦖以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0;//1不是素数
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            Prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&& i*Prime[j]<=n;j++){
            isPrime[i*Prime[j]] = 0;//筛选出i*Prime[j]的因子。
            if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
                break; //保证每个合数只被它的最小质因数筛掉一次，从而实现 O(n) 的线性时间复杂度。
        }
    }
}

int main() {
    int k=1;
    int n;
    int sum=0;
    scanf("%d", &n);//先读入 n（筛素数的上限）和 q（查询次数）；
    GetPrime(100000);
    if(n<2) {
        printf("0\n");
        return 0;
    } else if(n==2) {
        printf("2\n1\n");
        return 0;
    }
    while(sum<n){
        if(sum + Prime[k] > n)
            break;
        sum=sum+Prime[k];
        cout<<Prime[k]<<endl;
        k++;
    }

    cout<<k-1<<endl;
    //cout<<sum<<endl;
    return 0;
}