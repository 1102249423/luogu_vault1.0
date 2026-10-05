//cjf 君懒鬼有一说一
#include <bits/stdc++.h>
using namespace std;
int n;
//double distance1;//滥用全局变量 distance1 增加代码隐患。
double distance2;
struct wdnmd {
    int id;
    string name;
    int year;
    int month;
    int day;
}qiezi[114511];
bool compare1(wdnmd a,wdnmd b) {
    if (a.year!=b.year) {
        return a.year<b.year;
    }else {
        if (a.month!=b.month) {
            return a.month<b.month;
        }else{
            if (a.day!=b.day) {
                return a.day<b.day;
            }else {
                return a.id>b.id;
            }
        }
    }
}
//better
bool compare2(wdnmd a,wdnmd b) {
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    if(a.day != b.day) return a.day < b.day;
    return a.id > b.id; // 同一天，id大的放前面
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++) {
        qiezi[i].id=i;
        cin>>qiezi[i].name>>qiezi[i].year>>qiezi[i].month>>qiezi[i].day;
    }
    sort(qiezi+1,qiezi+n+1,compare1);
    for (int i=1;i<=n;i++) {
        cout<<qiezi[i].name;
        cout<<endl;
    }

    return 0;

}