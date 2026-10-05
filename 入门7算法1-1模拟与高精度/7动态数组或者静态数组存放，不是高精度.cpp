//顺时针旋转90度
//原位置(i, j)的元素会移动到新位置(j, m-1-i)
//或者从新位置看：新位置(i, j)的元素来自原位置(m-1-j, i
//逆时针旋转90度
//原位置(i, j)的元素会移动到新位置(m-1-j, i)
//或者从新位置看：新位置(i, j)的元素来自原位置(j, m-1-i)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;


    /*  vector 是 C++ 标准库的动态数组（比普通数组更安全、更方便）
        vector<int>：存放整数的一维动态数组
        vector<int>(n)构造一个长度为 n 的一维 int 数组所有元素自动初始化为 0
        vector<vector<int>>外层也是一个 vector里面存放的元素是 vector<int>合起来就是：存放 “一维数组” 的数组 → 二维数组

        vector<int> a;          // 空的 int 数组
        vector<int> a(n);       // 大小为 n，初始值都是 0
        vector<int> a(n, 5);    // 大小为 n，每个元素都是 5
        vector<vector<int>> a(n, vector<int>(m)); // n行m列二维数组

        vector<vector<int>> matrix(n, vector<int>(n));
        matrix：二维数组的变量名
        第一个 n：二维数组有 n 行
        第二个 vector<int>(n)：每一行都是一个长度为 n 的一维数组

        // 给第 i 行第 j 列赋值
        matrix[i][j] = 10;

        // 读取第 i 行第 j 列的值
        int value = matrix[i][j];
     *
     */
    vector<vector<int>> matrix(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = num++;
        }
    }

    // 2. 处理m次操作
    for (int k = 0; k < m; k++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;

        // 🦖转换为0-based索引，计算机从0开始计算
        x--; y--;

        // 子矩阵大小
        int size = 2 * r + 1;

        // 创建临时矩阵存储子矩阵
        vector<vector<int>> temp(size, vector<int>(size));

        // 提取子矩阵
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //取一个以 (x,y) 为中心的正方形回到左上角原点
                temp[i][j] = matrix[x - r + i][y - r + j];
            }
        }

        // 🦖旋转子矩阵
        if (z == 0) {  // 顺时针
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    //这里用size-1-j通过枚举可以得到，-1是因为从零开始的计算
                    matrix[x - r + i][y - r + j] = temp[size - 1 - j][i];
                }
            }
        } else {  // 逆时针
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[x - r + i][y - r + j] = temp[j][size - 1 - i];
                }
            }
        }
    }

    // 🦖输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}


/**使用古法静态数组
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 1. 初始化矩阵
    int matrix[510][510] = {0};  // 多开一些空间
    int num = 1;
    for (int i = 1; i <= n; i++) {  // 用1-based索引
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = num++;
        }
    }

    // 临时数组存储子矩阵
    int temp[510][510] = {0};

    // 2. 处理m次操作
    for (int k = 0; k < m; k++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;

        int size = 2 * r + 1;

        // 提取子矩阵到temp
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                temp[i][j] = matrix[x - r + i][y - r + j];
            }
        }

        // 旋转并放回
        if (z == 0) {  // 顺时针
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[x - r + i][y - r + j] = temp[size - 1 - j][i];
                }
            }
        } else {  // 逆时针
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[x - r + i][y - r + j] = temp[j][size - 1 - i];
                }
            }
        }
    }

    // 3. 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j];
            if (j < n) cout << " ";
        }
        cout << endl;
    }

    return 0;
}



 */



