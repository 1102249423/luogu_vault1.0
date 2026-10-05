#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];//🦖两个数组循环展示就可以啦
int b[1000][1000];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            cin>>a[i][j];

        }
    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            if (a[i][j]=='*'){
                if(i-1>=0){
                    b[i-1][j]++;
                }
                if(j-1>=0){
                    b[i][j-1]++;
                }
                if((i-1>=0)&&(j-1>=0)){
                    b[i-1][j-1]++;
                }

                if(i+1<n){
                    b[i+1][j]++;
                }
                if(j+1<m){
                    b[i][j+1]++;
                }
                if((i+1<n)&&(j+1<m)){
                    b[i+1][j+1]++;
                }

                if((i-1>=0)&&(j+1<m)){
                    b[i-1][j+1]++;
                }
                if((i+1<n)&&(j-1>=0)){
                    b[i+1][j-1]++;
                }
            }
        }
    }
//    for (int i = 0; i <n ; ++i) {
//        for (int j = 0; j <m ; ++j) {
//            if(a[i][j]!='*'){
//                //a[i][j]='b[i][j]';//你把一个变量名写进单引号，编译器根本不认识
//               /**
//                    0 + '0' = '0'
//                    1 + '0' = '1'
//                    2 + '0' = '2'
//                    ...
//                    9 + '0' = '9'
//               **/
//                a[i][j] = b[i][j] + '0'; //🦖输出转化
//            }
//        }
//    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                cout << '*';
            } else {
                cout << b[i][j];  // 输出周围地雷数
            }
        }
        cout << endl;
    }

    return 0;
}