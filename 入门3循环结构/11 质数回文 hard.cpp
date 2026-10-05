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
            if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
             break; //保证每个合数只被它的最小质因数筛掉一次，从而实现 O(n) 的线性时间复杂度。
             //i=6，isPrime[6]=0（已被筛过），所以不会加入 Prime 数组，
             //6=2×3，2 是 6 的最小质因数；如果继续 j=2（Prime [2]=3），会计算 6×3=18，标记 isPrime [18]=0，但 18 的最小质因数是 2，应该留给 i=9（9=3×3）、j=1（Prime [1]=2）时，计算 9×2=18 来标记 → 避免重复。
        }
    }
}
//🦖 方法一：字符串判断
bool isPalindrome1(int n) {
    string s = to_string(n);//🦖to_string() 是 C++ 标准库自带的函数，无需自定义
    int left = 0, right = s.size() - 1;//🦖s.size() 是 C++ std::string 类的成员方法，核心作用是获取字符串的有效字符个数
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
// 🦖方法二：数字反转
bool isPalindrome2(int n) {
    int reversed = 0;// 存储反转后的数字
    int original = n;// 保存原始数字
    while (n > 0) {
        // reversed向左移动一位（×10），加上n的最后一位
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed == original;
}
// 🦖方法三：只反转一半数字进行比较
bool isPalindrome3(int n) {
    // 负数不是回文数， 个位是0但本身不是0
    if (n < 0 || (n % 10 == 0 && n != 0)) return false;

    int reversed = 0;// 存储反转的后半部分
    while (n > reversed) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    // 偶数位：n == reversed
    // 奇数位：n == reversed / 10
    return n == reversed || n == reversed / 10;
}
int main() {
    int a,b;
    int sum=0;
    scanf("%d %d", &a,&b);//先读入 n（筛素数的上限）和 q（查询次数）；
    GetPrime(b);

    for(int i=1;i<=cnt;i++){
        int p=Prime[i];
        if(p>=a && p<=b && isPalindrome3(p)){
            cout<<p<<endl;
        }
    }

    return 0;
}