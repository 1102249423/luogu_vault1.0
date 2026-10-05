#include <bits/stdc++.h>
using namespace std;
int n;

struct student
{
    string id;
    int chinese,math,zongfen;
    double zonghe;
    void calculate_zonghe() {
        zonghe = chinese*0.7 + math*0.3;
    }
    int calculate_zongfen() {
        zongfen = chinese+math;
        return zongfen;
    }

}students[11451];
bool worthy_excellent(student a)
{
    if(abs(a.zongfen)>140&&abs(a.chinese*7+a.math*3)>=800){
        return true;
    }else{
        return false;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> students[i].id;
        cin >> students[i].chinese;
        cin >> students[i].math;
        students[i].calculate_zonghe();
        students[i].calculate_zongfen();
       if( worthy_excellent(students[i])){
           cout<<"Excellent"<<endl;
       }else{
           cout<<"Not excellent"<<endl;
       }
    }
}