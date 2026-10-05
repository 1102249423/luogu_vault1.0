//#include <bits/stdc++.h>
//using namespace std;
//int a,b;
//int ans[10];
//int temp,temp1,temp2;
//int main(){
//    cin>>a>>b;
//    for(int i=a;i<=b;i++){
//        temp=i;
//        while(temp>10){
//            temp1=temp%10;
//            ans[temp1]++;
//            temp/=10;
//            if(temp<10){//🦖最高位补丁，但是还是不对
//                ans[temp]++;
//            }
//        }
//
//    }
//    for(int i=0;i<10;i++){
//        cout<<ans[i]<<" ";
//    }
//}
//🦖正解
#include <bits/stdc++.h>
using namespace std;
int a,b;
int ans[10];
int temp,temp1,temp2;
int main(){
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        temp=i;
        while(temp!=0){
            temp1=temp%10;
            ans[temp1]++;
            temp/=10;
        }

    }
    for(int i=0;i<10;i++){
        cout<<ans[i]<<" ";
    }
}
//🦖大爱string
//#include <bits/stdc++.h>
//using namespace std;
//#define in cin
//#define out cout
//#define int long long
//int cnt[10]; //储存数量
//
//signed main() {
//    int l, r;
//    in >> l >> r;
//    for (int i = l; i <= r; i++) {
//        string s = to_string(i); // 将i转化为string类型
//        for (int j = 0; j < s.size(); j++) // 遍历s
//            cnt[s[j] - '0']++; // 统计数字的出现数量
//    }
//    for (int i = 0; i < 10; i++) // 输出答案
//        out << cnt[i] << ' ';
//    return 0;
//}
