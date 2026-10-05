#include <bits/stdc++.h>
using namespace std;

double jisuanchengji(int a[], int len){
    sort(a, a + len);  // 排序：从小到大
    int sum=0;
    for (int i = 1; i < len - 1; i++) {
        sum += a[i];
    }
    return (double)sum / (len - 2);  // 平均分
}
int main(){
    int n,m;
    int a[1000];
    cin>>n>>m;
    double max_score = 0;  // 记录最高分的同学
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            cin>>a[j];
        }
        double avg = jisuanchengji(a, m);

        if (avg > max_score) {
            max_score = avg;
        }

    }
    cout << fixed << setprecision(2);
    cout << max_score << endl;
    return 0;
}
/**结构体 参照第七题
* #include <bits/stdc++.h>
using namespace std;

struct student
{
	int id, a[25], maxa = -1, mina = 11;
	double ave, tot;
}students[105];//tudents[105]就是用一个数组来存储105个学生的信息，而数组的每个元素都是一个 struct student类型的变量。


int n, m;
//当a.ave < b.ave时，返回true
//
//当a.ave >= b.ave时，返回false
//
//这意味着按照平均分从小到大（升序）排序
     //sort(students, students + 105, cmp);
     //// 先按平均分降序，平均分相同再按学号升序
     //bool cmp(student a, student b) {
     //    if(a.ave != b.ave)
     //        return a.ave > b.ave;  // 平均分高的在前
     //    else
     //        return a.id < b.id;    // 平均分相同时，学号小的在前
     //}
bool cmp(student a, student b)
{
	return a.ave < b.ave;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> students[i].a[j];
			students[i].tot += students[i].a[j];
			students[i].maxa = max(students[i].a[j], students[i].maxa);//🦖较大值的封装不再使用if
			students[i].mina = min(students[i].a[j], students[i].mina);
		}
		students[i].tot -= (students[i].maxa + students[i].mina);
		students[i].ave = students[i].tot * 1.0 / (m - 2);
	}
	sort(students + 1, students + n + 1, cmp);//🦖数组排序封装
	cout << fixed << setprecision(2) << students[n].ave << endl;
	return 0;
}

*/