/*
注意：C++ 中的数组下标从 0 开始，x 轴是竖直方向，从上到下增大；
 y 轴是水平方向，从左到右增大，与数学中的坐标系不完全相同。
      0   1   2   3   4   5   6   7   8 (y)
    ┌───┬───┬───┬───┬───┬───┬───┬───┐
 0  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 1  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 2  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 3  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 4  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 5  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 6  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 7  │   │   │   │   │   │   │   │   │
    ├───┼───┼───┼───┼───┼───┼───┼───┤
 8  │   │   │   │   │   │   │   │   │
    └───┴───┴───┴───┴───┴───┴───┴───┘
(x)
 数组元素位置表示为 arr[x][y]，其中：
x：行号（竖直方向，从上到下为 0~8）
y：列号（水平方向，从左到右为 0~8）
示例：左上角元素坐标为 (0,0)，对应 arr[0][0]；右下角元素坐标为 (8,8)，对应 arr[8][8]
 * */
//加了左边确实不越界但是右边报错
//#include<bits/stdc++.h>
//using namespace std;
//int a[500][500];
//int huo1,huo2;
//int ying1,ying2;
//int main() {
//    int n,m,k;
//    cin>>n>>m>>k;
//
//    for(int i=1;i<=k;i++){
//        cin>>huo1>>huo2;
//        huo1+=50;
//        huo2+=50;
//                a[huo1-2][huo2]=1;
//
//                a[huo1-1][huo2-1]=1;
//                a[huo1-1][huo2]=1;
//                a[huo1-1][huo2+1]=1;
//
//                a[huo1][huo2-2]=1;
//                a[huo1][huo2-1]=1;
//                a[huo1][huo2]=1;
//                a[huo1][huo2+1]=1;
//                a[huo1][huo2+2]=1;
//
//                a[huo1+1][huo2-1]=1;
//                a[huo1+1][huo2]=1;
//                a[huo1+1][huo2+1]=1;
//
//                a[huo1+2][huo2]=1;
//
//
//
//    }
//    for(int i=1;i<=m;i++){
//        cin>>ying1>>ying2;
//        ying1+=50;
//        ying2+=50;
//        for(int x=ying1-2;x<=ying1+2;x++){
//            for(int y=ying2-2;y<=ying2+2;y++){
//                a[x][y]=1;
//            }
//        }
//
//
//    }
//
//    for(int i=51;i<=n+50;i++){
//        for (int j = 51; j <= n+50; ++j) {
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
//
//}
//
#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, ans;
int s[5005][5005];
bool pd(int x, int y) { //判断是否越界
    if(x < 1 || y < 1 || x > n || y > n) return 0;
    return 1;
}
int main() {
    scanf("%d%d%d", &n, &m, &k); //读入
    for(int i = 1; i <= m + k; i++) { //由于计算火把和萤石的步骤很像，所以合并了
        scanf("%d%d", &a, &b); //读入坐标
        for(int x = -2; x <= 2; x++)
            for(int y = -2; y <= 2; y++) //枚举5*5的方阵(通过计算距离)
                if((i > m || abs(x) + abs(y) <= 2) && pd(x + a, b + y))
                    //若 i > m（当前是萤石）：条件直接成立 → 5×5 方阵内所有未越界的格子都被照亮；
                    //若 i ≤ m（当前是火把）：仅当 abs(x)+abs(y) ≤2（曼哈顿距离≤2）时成立 → 只照亮十字形区域（排除斜方向 2 格的位置）。
                    s[x + a][b + y]++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += s[i][j] == 0; //枚举每一个方格，看看是不是==0(即没有亮光)
    printf("%d\n", ans); //输出结果
    return 0;
}

/**
* #include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, ans;
int s[5005][5005]; // 标记每个格子是否被照亮（0=未照亮，≥1=已照亮）

// 越界检查：判断(x,y)是否在n×n网格内（下标1~n）
bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    // ========== 1. 处理所有火把（完全枚举所有照亮的位置，不用曼哈顿距离） ==========
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b); // 火把坐标(a,b)

        // 火把照亮规则：以(a,b)为中心，以下这些位置全部照亮（对应曼哈顿距离≤2）
        // 第1类：火把自身
        if (is_valid(a, b)) s[a][b]++;

        // 第2类：上下左右1格（距离1）
        if (is_valid(a-1, b)) s[a-1][b]++;
        if (is_valid(a+1, b)) s[a+1][b]++;
        if (is_valid(a, b-1)) s[a][b-1]++;
        if (is_valid(a, b+1)) s[a][b+1]++;

        // 第3类：上下左右2格（距离2）
        if (is_valid(a-2, b)) s[a-2][b]++;
        if (is_valid(a+2, b)) s[a+2][b]++;
        if (is_valid(a, b-2)) s[a][b-2]++;
        if (is_valid(a, b+2)) s[a][b+2]++;

        // 第4类：斜方向1格（距离2：1+1）
        if (is_valid(a-1, b-1)) s[a-1][b-1]++;
        if (is_valid(a-1, b+1)) s[a-1][b+1]++;
        if (is_valid(a+1, b-1)) s[a+1][b-1]++;
        if (is_valid(a+1, b+1)) s[a+1][b+1]++;
    }

    // ========== 2. 处理所有萤石（完全枚举5×5方阵的所有位置） ==========
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &a, &b); // 萤石坐标(a,b)

        // 萤石照亮规则：以(a,b)为中心，5×5方阵的所有位置（逐行枚举，无遗漏）
        // 行偏移：-2、-1、0、1、2
        if (is_valid(a-2, b-2)) s[a-2][b-2]++;
        if (is_valid(a-2, b-1)) s[a-2][b-1]++;
        if (is_valid(a-2, b))   s[a-2][b]++;
        if (is_valid(a-2, b+1)) s[a-2][b+1]++;
        if (is_valid(a-2, b+2)) s[a-2][b+2]++;

        if (is_valid(a-1, b-2)) s[a-1][b-2]++;
        if (is_valid(a-1, b-1)) s[a-1][b-1]++;
        if (is_valid(a-1, b))   s[a-1][b]++;
        if (is_valid(a-1, b+1)) s[a-1][b+1]++;
        if (is_valid(a-1, b+2)) s[a-1][b+2]++;

        if (is_valid(a, b-2))   s[a][b-2]++;
        if (is_valid(a, b-1))   s[a][b-1]++;
        if (is_valid(a, b))     s[a][b]++;
        if (is_valid(a, b+1))   s[a][b+1]++;
        if (is_valid(a, b+2))   s[a][b+2]++;

        if (is_valid(a+1, b-2)) s[a+1][b-2]++;
        if (is_valid(a+1, b-1)) s[a+1][b-1]++;
        if (is_valid(a+1, b))   s[a+1][b]++;
        if (is_valid(a+1, b+1)) s[a+1][b+1]++;
        if (is_valid(a+1, b+2)) s[a+1][b+2]++;

        if (is_valid(a+2, b-2)) s[a+2][b-2]++;
        if (is_valid(a+2, b-1)) s[a+2][b-1]++;
        if (is_valid(a+2, b))   s[a+2][b]++;
        if (is_valid(a+2, b+1)) s[a+2][b+1]++;
        if (is_valid(a+2, b+2)) s[a+2][b+2]++;
    }

    // ========== 3. 统计未被照亮的格子 ==========
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 0) { // 未被任何光源照亮
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
*/