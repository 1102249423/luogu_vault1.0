//#include <bits/stdc++.h>
//using namespace std;
//int n;
//double a[5000];
//int t[5000];
//int main(){
//    cin>>n;
//    for (int i = 0; i < n; ++i) {
//        cin>>a[i]>>t[i];
//    }
//
//
//    cout<<max2<<endl;
//    return 0;
//}
//
//🦖过于巧妙了直接不用数组，结果反正二进制直接表示了
#include<bits/stdc++.h>
using namespace std;
int n,t,ans,x;
double a;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>t;
        for(int i=1;i<=t;i++){
            x=(int)(a*i);//a*i为当前灯的编号
            ans^=x;//异或(・∀・(・∀・(・∀・*)
        }
    }
    cout<<ans;
    return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN = 2000001;
//int light[MAXN];//状态表示。
//int n, t;
//double a;
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> a >> t;
//        for (int j = 1; j <= t; j++) {
//            int index = (int)(j * a);
//            light[index] ^= 1;//切换状态。
//        }
//    }
//    //找出唯一亮着的灯。
//    for (int i = 2; i <= MAXN; i++) {
//        if (light[i] == 1) {
//            cout << i << endl;
//            break;
//        }
//    }
//
//    return 0;
//}