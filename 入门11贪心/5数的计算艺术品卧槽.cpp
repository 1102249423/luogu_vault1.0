#include<bits/stdc++.h>
using namespace std ;
int n ;
int f[1005] ;//存放的是这个数开头能衍生的数列个数。且我们的 DP 递推顺序天然完成了初始化，不需要手动赋值。
int main()
{
    cin >> n ;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= i / 2 ; j++ )
        {
            f[i] += f[j] ;
        }
        f[i]++ ;
    }
    cout << f[n] ;
    return 0 ;
}
