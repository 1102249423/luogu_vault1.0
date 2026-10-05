#include <bits/stdc++.h>
using namespace std;
int n,na,nb;
int a[114511];
int b[114511];
int suma,sumb;
signed main(){
    suma=sumb=0;
    cin>>n>>na>>nb;
    for (int i = 0; i < na; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < nb; ++i) {
        cin>>b[i];
    }
    for (int i = 0; i < n; ++i) {
        int ia=i;
        int ib=i;
//        while(ia>na-1){
//            ia-=na;
//        }
//        while(ib>nb-1){
//            ib-=nb;
//        }
//1这是标准做法，其他程序员更容易理解
//2效率更高
//3代码更简洁
//4在处理大范围数据时更可靠
        ia=i % na;
        ib=i % nb;

        if(a[ia]==0&&b[ib]==1){
            sumb++;//
        }else if(a[ia]==0&&b[ib]==2){
            suma++;//
        }else if(a[ia]==0&&b[ib]==3){
            suma++;//
        }else if(a[ia]==0&&b[ib]==4){
            sumb++;//
        }else if(a[ia]==1&&b[ib]==2){
            sumb++;//
        }else if(a[ia]==1&&b[ib]==3){
            suma++;//
        }else if(a[ia]==1&&b[ib]==4) {
            sumb++;//
        }else if(a[ia]==2&&b[ib]==3){
            sumb++;
        }else if(a[ia]==2&&b[ib]==4){
            suma++;
        }else if(a[ia]==3&&b[ib]==4){
            suma++;//end
        }//反过来你没写！！！
        else if(a[ia]==1&&b[ib]==0){
            suma++;//
        }else if(a[ia]==2&&b[ib]==0){
            sumb++;//
        }else if(a[ia]==3&&b[ib]==0){
            sumb++;//
        }else if(a[ia]==4&&b[ib]==0){
            suma++;//
        }else if(a[ia]==2&&b[ib]==1){
            suma++;//
        }else if(a[ia]==3&&b[ib]==1){
            sumb++;//
        }else if(a[ia]==4&&b[ib]==1) {
            suma++;//
        }else if(a[ia]==3&&b[ib]==2){
            suma++;
        }else if(a[ia]==4&&b[ib]==2){
            sumb++;
        }else if(a[ia]==4&&b[ib]==3){
            sumb++;//end
        }
    }
    cout<<suma<<" "<<sumb<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int n, na, nb;
int a[205], b[205];
int suma, sumb;

// 胜负表：win[i][j] = 1 表示 i 赢 j，0 表示平，-1 表示 i 输 j
int win[5][5] = {
    {0, -1, 1, 1, -1}, // 0 对 0,1,2,3,4
    {1, 0, -1, 1, -1}, // 1
    {-1, 1, 0, -1, 1}, // 2
    {-1, -1, 1, 0, 1}, // 3
    {1, 1, -1, -1, 0}  // 4
};

int main() {
    cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i) cin >> a[i];
    for (int i = 0; i < nb; ++i) cin >> b[i];

    suma = sumb = 0;
    for (int i = 0; i < n; ++i) {
        int ia = i % na;
        int ib = i % nb;
        int res = win[a[ia]][b[ib]];
        if (res == 1) suma++;
        else if (res == -1) sumb++;
    }
    cout << suma << " " << sumb << endl;
    return 0;
}





 */