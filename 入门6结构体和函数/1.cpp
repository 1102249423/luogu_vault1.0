#include <bits/stdc++.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
    double a, b, c;
    a = x1 - x2;
    b = y1 - y2;
    c = sqrt(a * a + b * b);
    return c;
}
double juli(double x1,double y1,double x2,double y2){
    double a, b, c;
    a = x1 - x2;
    b = y1 - y2;
    c = sqrt(a * a + b * b);
    return c;
}
int main(){
    double x[4],y[4];
    for(int i=1;i<4;i++){
        cin>>x[i]>>y[i];
    }
    double c=juli(x[1],y[1],x[2],y[2])
            +juli(x[2],y[2],x[3],y[3])
            +juli(x[1],y[1],x[3],y[3]);;

    cout<<fixed<<setprecision(2)<<c<<endl;//🦖保留函数写法
    return 0;
}