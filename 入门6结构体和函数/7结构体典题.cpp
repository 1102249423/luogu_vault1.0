#include <bits/stdc++.h>
using namespace std;
int n;

struct student
{
    string id;
    int chinese,math,english,zongfen;
    // 🦖不能在结构体内部这样直接赋值。你在结构体内部写的 zongfen=chinese+math+english;是错误的，因为结构体内部只能声明成员变量，不能直接写赋值语句。
    //zongfen=chinese+math+english;
    //要么主函数里面，要么这里面加一个成员函数
    void calculate_zongfen() {
        zongfen = chinese + math + english;
    }

}students[11451];//students[105]就是用一个数组来存储105个学生的信息，而数组的每个元素都是一个 struct student类型的变量。

bool cmp(student a, student b)
{
    return a.zongfen < b.zongfen;
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
        if(students[i].zongfen>max_zongfen){
            max_zongfen = students[i].zongfen;
            flag=i;
        }
    }
    if(flag==0){
        flag=1;
    }
    cout<< students[flag].id<<" ";
    cout<< students[flag].chinese<<" ";
    cout<<  students[flag].math<<" ";
    cout<<  students[flag].english<< endl;

}