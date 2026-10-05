#include <bits/stdc++.h>
using namespace std;
int n;
//double distance1;//滥用全局变量 distance1 增加代码隐患。
double distance2;
struct wdnmd {
    double x;
    double y;
    double z;
}qiezi[114511];
bool compare1(wdnmd a,wdnmd b) {
    if (a.z!=b.z)
        return a.z<b.z;
    return a.x<b.x;
}

double get_distance(double x1,double y1 ,double z1,double x2,double y2 ,double z2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}
//int cnt=0;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>qiezi[i].x>>qiezi[i].y>>qiezi[i].z;
    }
    sort(qiezi+1,qiezi+n+1,compare1);
    for (int i=1;i<=n;i++) {
        //cout<<qiezi[i].x<<" "<<qiezi[i].y<<" "<<qiezi[i].z;
        //cout<<endl;
        if (i!=n) {
            distance2+=get_distance(qiezi[i].x,qiezi[i].y,qiezi[i].z,qiezi[i+1].x,qiezi[i+1].y,qiezi[i+1].z);
        }
    }
    //🦖setprecision(k)：保留 k 位小数
    cout<<fixed<<setprecision(3)<<distance2<<endl;
    return 0;

}