#include <bits/stdc++.h>
using namespace std;
int n;

struct student
{
    string id;
    int chinese,math,english,zongfen;
    void calculate_zongfen() {
        zongfen = chinese + math + english;
    }

}students[11451];//students[105]就是用一个数组来存储105个学生的信息，而数组的每个元素都是一个 struct student类型的变量。

bool worthy_opponent(student a, student b)
{
    if(abs(a.chinese-b.chinese)<=5&&abs(a.math-b.math)<=5&&abs(a.english-b.english)<=5&&abs(a.zongfen-b.zongfen)<=10){
        return true;
    }else{
        return false;
    }
//    return a.zongfen < b.zongfen;
}

int main()
{
    int max_zongfen=0;
    int flag=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> students[i].id;
        cin >> students[i].chinese;
        cin >> students[i].math;
        cin >> students[i].english;
        students[i].calculate_zongfen();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if(worthy_opponent(students[i],students[j])){
                cout<< students[i].id<<" "<<students[j].id<<endl;
            }
        }
    }

}