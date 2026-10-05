//对于这组输入：
//11
//99 50 49 48 51 47 46 53 52 45 54
//虽然有很多对数的和等于 99（比如 45+54、46+53 等），
// 但题目问的是有多少个不同的数能表示为另外两数之和，而不是有多少种加法。


#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int sum=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[i]+a[j]==a[k]){
                    sum++;
                    cout<<a[i]<<"+"<<a[j]<<"=="<<a[k]<<endl;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}

//🦖桶排序德思路眼前一亮
//#include <iostream>
//using namespace std;
//
//const int N = 105, M = 2e4 + 5;//t要开到20000。因为一个数大小不超过10000，两个数的和就不超过20000
//
//int a[N];
//bool f[M];
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//        f[a[i]] = true;
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//        for (int j = i + 1; j <= n; j++)
//            if (f[a[i] + a[j]])
//            {
//                ans++;
//                f[a[i] + a[j]] = false;
//            }
//    cout << ans;
//    return 0;
//}
