//#include <bits/stdc++.h>
//using namespace std;
//int n;
//int a[114511];
//int main(){
//    cin>>n;
//    for (int i = 0; i <n ; ++i) {
//        cin>>a[i];
//    }
//
//    for (int i = 0; i <n ; ++i) {
//        int first=0;
//        if(a[i]==0){
//            if(i==first){
//                first=i;
//            }
//        }else if(first==i){
//            cout<<a[i]<<"x"<<"^"<<i;
//        }else
//            if(a[i]>0){
//                if(a[i]==1){
//                    cout<<"+"<<"x"<<"^"<<i;
//                }else{
//                    cout<<"+"<<a[i]<<"x"<<"^"<<i;
//                }
//
//            }else{
//                if(a[i]==-1){
//                    cout<<"-"<<"x"<<"^"<<i;
//                }else{
//                    cout<<"-"<<a[i]<<"x"<<"^"<<i;
//                }
//            }
//    }
//
//    return 0;
//}
//kkrj，你写的就是垃圾QAQ
//写的太漂亮了
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a; cin >> n;
    for(int i=n; i>=0; i--){
        cin >> a;
        if(a){
            if(i<n&&a>0) cout << '+';//i < n: 当前项不是第一项（不是最高次项）。a > 0: 系数是正数
            if(abs(a)>1||i==0) cout << a;//abs(a) > 1: 系数的绝对值大于 1。i == 0: 当前项是常数项（0次项）
            if(a==-1&&i) cout << '-';// 当系数为 -1 且不是常数项时，输出负号
            if(i>0) cout << 'x'; //输出变量 x（如果不是常数项）
            if(i>1) cout << '^' << i;// 输出指数（如果次数大于 1）
        }
    }
    return 0;
}
