//打擂台方法
//#include <bits/stdc++.h>
//using namespace std;
//int a[110];
//int main(){
//    int n;
//    int nmin=1001;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//        if(a[i]<nmin) nmin=a[i];
//    }
//    cout<<nmin<<endl;
//    return 0;
//}
//用stl标准库的快排🦖
/**sort 是 C++ STL（标准模板库）里的排序函数，定义在 <algorithm> 头文件中
 * （你的 bits/stdc++.h 已经包含了这个头文件，所以可以直接用）。
 *sort(a+1,a+1+n);
 *a+1：数组 a 的第 1 个元素（a[1]）的地址（因为你数组下标从 1 开始）。
 *a+1+n：数组 a 的第 n 个元素（a[n]）的下一个地址。
 * 左闭右开
 *  #include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;   // 姓名
    int total;     // 总分
    int chinese;   // 语文分
};

// 自定义cmp：多条件排序
bool cmp(Student s1, Student s2) {
    // 条件1：总分不同 → 总分高的在前
    if (s1.total != s2.total) {
        return s1.total > s2.total;
    }
    // 条件2：总分相同 → 语文分低的在前
    if (s1.chinese != s2.chinese) {
        return s1.chinese < s2.chinese;
    }
    // 条件3：语文分也相同 → 姓名字典序小的在前
    return s1.name < s2.name;
}

int main() {
    Student stu[] = {
        {"张三", 280, 95},
        {"李四", 285, 90},
        {"王五", 280, 88},
        {"赵六", 280, 88},
        {"钱七", 280, 88}
    };
    sort(stu, stu+5, cmp);
    // 输出顺序：李四（285）→ 王五（280/88）→ 钱七（280/88）→ 赵六（280/88）→ 张三（280/95）
    for (int i=0; i<5; i++) {
        cout << stu[i].name << " " << stu[i].total << " " << stu[i].chinese << endl;
    }
    return 0;
}
 */

//#include<bits/stdc++.h>//万能头。
//using namespace std;
//int n,a[110];
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    sort(a+1,a+1+n);//排序。
//    cout<<a[1];//输出最小值。
//    return 0;
//}

//桶排序🦖
#include<bits/stdc++.h>
using namespace std;
int n,a[110],tong[1010];//tong 的大小就是 a 数组的值域。
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tong[a[i]]++;
    }
    for(int i=0;i<=1000;i++){//a 的值域。
        if(tong[i]!=0){//找到第一个出现的数。
            cout<<i;
            return 0;
        }
    }
}
