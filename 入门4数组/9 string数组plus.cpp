//#include <bits/stdc++.h>
//using namespace std;
//int n;
//int a[100];
//void print11(){
//    cout<<"XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX"<<endl;
//    cout<<"X.X...X...X...X.X.X.X...X.....X.X.X.X.X"<<endl;
//    cout<<"X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX"<<endl;
//    cout<<"X.X...X.X.....X...X...X.X.X...X.X.X...X"<<endl;
//    cout<<"XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX"<<endl;
//}
//void print_void(){
//    cout<<"."<<endl;
//    cout<<"."<<endl;
//    cout<<"."<<endl;
//    cout<<"."<<endl;
//    cout<<".";
//}
//void print0(){
//    cout<<"XXX"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX";
//
//}
//void print1(){
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//
//}
//void print2(){
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"X.."<<endl;
//    cout<<"XXX"<<endl;
//
//}
//void print3(){
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"XXX"<<endl;
//
//}
//void print4(){
//    cout<<"X.X"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//}
//void print5(){
//    cout<<"XXX"<<endl;
//    cout<<"X.."<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"XXX"<<endl;
//
//}
//void print6(){
//    cout<<"XXX"<<endl;
//    cout<<"X.."<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX"<<endl;
//
//}
//void print7(){
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"..X"<<endl;
//
//}
//void print8(){
//    cout<<"XXX"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX"<<endl;
//
//}
//void print9(){
//    cout<<"XXX"<<endl;
//    cout<<"X.X"<<endl;
//    cout<<"XXX"<<endl;
//    cout<<"..X"<<endl;
//    cout<<"XXX"<<endl;
//}
//
//int main(){
//    int flag=0;
//    cin>>n;
//    for (int i = 0; i <n ; ++i) {
//        cin>>a[i];
//    }
//    for (int i = 0; i <n ; ++i) {
//        flag++;
//        if(a[i]==0){
//            print0();
//        }else if(a[i]==1){
//            print1();
//        }else if(a[i]==2){
//            print2();
//        }else if(a[i]==3){
//            print3();
//        }else if(a[i]==4){
//            print4();
//        }else if(a[i]==5){
//            print5();
//        }else if(a[i]==6){
//            print6();
//        }else if(a[i]==7){
//            print7();
//        }else if(a[i]==8){
//            print8();
//        }else if(a[i]==9){
//            print9();
//        }
//        if(flag!=n){
//            print_void();
//        }
//    }
//    //print1();
//    return 0;
//}
//version0.2
//🦖本题可以学到的是数组可以存放string，上一题呢解释了二维数组的坐标处理。
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    // 存储5行的输出字符串
//    string ans[5];
//
//    for (int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//
//        // 根据数字添加对应的图案
//        if (num == 0) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "X.X"; ans[2] += "X.X"; ans[3] += "X.X";
//        } else if (num == 1) {
//            ans[0] += "..X"; ans[4] += "..X";
//            ans[1] += "..X"; ans[2] += "..X"; ans[3] += "..X";
//        } else if (num == 2) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "..X"; ans[2] += "XXX"; ans[3] += "X..";
//        } else if (num == 3) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "..X"; ans[2] += "XXX"; ans[3] += "..X";
//        } else if (num == 4) {
//            ans[0] += "X.X"; ans[4] += "..X";
//            ans[1] += "X.X"; ans[2] += "XXX"; ans[3] += "..X";
//        } else if (num == 5) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "X.."; ans[2] += "XXX"; ans[3] += "..X";
//        } else if (num == 6) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "X.."; ans[2] += "XXX"; ans[3] += "X.X";
//        } else if (num == 7) {
//            ans[0] += "XXX"; ans[4] += "..X";
//            ans[1] += "..X"; ans[2] += "..X"; ans[3] += "..X";
//        } else if (num == 8) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "X.X"; ans[2] += "XXX"; ans[3] += "X.X";
//        } else if (num == 9) {
//            ans[0] += "XXX"; ans[4] += "XXX";
//            ans[1] += "X.X"; ans[2] += "XXX"; ans[3] += "..X";
//        }
//
//        // 如果不是最后一个数字，添加分隔符
//        if (i != n - 1) {
//            ans[0] += ".";
//            ans[1] += ".";
//            ans[2] += ".";
//            ans[3] += ".";
//            ans[4] += ".";
//        }
//    }
//
//    // 输出结果
//    for (int i = 0; i < 5; i++) {
//        cout << ans[i] << endl;
//    }
//
//    return 0;
//}
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    string ans[5];  // 存储5行的字符串

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        char c = s[i];//string类型支持像数组一样的下标访问。

        // 根据字符添加对应的点阵图案
        if (c == '0') {
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "X.X";
            ans[3] += "X.X";
            ans[4] += "XXX";
        } else if (c == '1') {
            ans[0] += "..X";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
            ans[4] += "..X";
        } else if (c == '2') {
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "X..";
            ans[4] += "XXX";
        } else if (c == '3') {
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        } else if (c == '4') {
            ans[0] += "X.X";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "..X";
        } else if (c == '5') {
            ans[0] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        } else if (c == '6') {
            ans[0] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "X.X";
            ans[4] += "XXX";
        } else if (c == '7') {
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
            ans[4] += "..X";
        } else if (c == '8') {
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "X.X";
            ans[4] += "XXX";
        } else if (c == '9') {
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        }

        // 如果不是最后一个数字，添加间隔点
        if (i != n - 1) {
            ans[0] += ".";
            ans[1] += ".";
            ans[2] += ".";
            ans[3] += ".";
            ans[4] += ".";
        }
    }

    // 输出结果
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}





























