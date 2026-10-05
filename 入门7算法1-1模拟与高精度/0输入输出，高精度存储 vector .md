🦖读取
```cpp
while(cin>>C)  // cin>> 会跳过空白字符（空格、换行、制表符等）
{
    if(C=='E')break;
    S+=C;
}
while(cin.get(C) && C != 'E')//读取包括空白字符在内的所有字符，应该用 cin.get(C)
{
    S += C;
}
```

🦖高精度
# 高精度运算与输入类型详解

## 一、高精度运算简介

### 什么是高精度？
当数字非常大，超过标准数据类型（int、long long等）的范围时，我们需要用特殊方法处理，这就是高精度运算。

**数据范围对比：**
- int：约 ±21亿（10位十进制数）
- long long：约 ±922亿亿（19位十进制数）


## 二、输入类型选择：char数组 vs string

### 1. 字符数组（char[]）

```cpp
// C风格字符串
char num1[2005], num2[2005];  // 多开一些空间
cin >> num1 >> num2;  // 或 scanf("%s%s", num1, num2);
```

**优点：**
- 简单直接，C语言兼容
- 内存连续，访问速度快
- 某些竞赛中可能略微更快

**缺点：**
- 需要预分配固定大小空间
- 容易越界
- 需手动处理字符串结束符'\0'
- 功能有限，不如string方便

### 2. string类

```cpp
// C++字符串类
#include <string>
using namespace std;
string num1, num2;
cin >> num1 >> num2;
```

**优点：**
- 动态分配内存，无需担心大小
- 丰富的成员函数（length(), reverse()等）
- 更安全，不易越界
- 支持运算符重载（+、=、==等）

**缺点：**
- 略微的内存开销
- 在某些老旧评测系统上可能稍慢

### 3. vector<int> 存储每一位数字
```cpp
vector<int> num = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};  // 低位在前
// 优点：运算方便，不需要类型转换
// 缺点：需要反转存储
```

### 4. 普通数组存储
```cpp
int num[1000] = {0};
// 优点：简单直接
// 缺点：需要预定义大小
```

---


# 高精度计算的存储方式选择

## 一、存储方式的选择

你说得对！高精度计算中，存储方式**没有必然的因果关系**，但各有优缺点。让我详细解释：

### 三种常用存储方式：

#### 1. **string 直接存储数字字符串**
```cpp
string num = "12345678901234567890";
// 优点：输入输出方便
// 缺点：运算时需要频繁 char ↔ int 转换
```

#### 2. **vector<int> 存储每一位数字**
```cpp
vector<int> num = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};  // 低位在前
// 优点：运算方便，不需要类型转换
// 缺点：需要反转存储
```

#### 3. **普通数组存储**
```cpp
int num[1000] = {0};
// 优点：简单直接
// 缺点：需要预定义大小
```

## 二、用 string 实现的阶乘和代码

```cpp
#include <iostream>
#include <string>
#include <algorithm>  // 用于reverse
using namespace std;

// 字符串乘法：大整数 × 小整数
string multiply(const string& a, int b) {
    string result = "";
    int carry = 0;
    
    for (int i = 0; i < a.length(); i++) {
        int digit = a[i] - '0';
        int temp = digit * b + carry;
        result += (temp % 10) + '0';  // 注意这里
        carry = temp / 10;
    }
    
    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    
    return result;
}

// 字符串加法
string add(const string& a, const string& b) {
    string result = "";
    int carry = 0;
    int i = 0;
    int len_a = a.length();
    int len_b = b.length();
    
    while (i < len_a || i < len_b || carry) {
        int sum = carry;
        if (i < len_a) sum += a[i] - '0';
        if (i < len_b) sum += b[i] - '0';
        
        result += (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    // 注意：这里字符串是倒着存的（低位在前）
    string fact = "1";  // 1! = 1
    string sum = "0";   // 初始和为0
    
    for (int i = 1; i <= n; i++) {
        fact = multiply(fact, i);  // 计算 i!
        sum = add(sum, fact);      // 累加到和
    }
    
    // 输出时反转（因为存储是低位在前）
    reverse(sum.begin(), sum.end());
    cout << sum << endl;
    
    return 0;
}
```

## 三、各种存储方式的对比

| 存储方式 | 优点 | 缺点 | 适用场景 |
|---------|------|------|---------|
| **string 字符数组** | 输入输出方便，无需转换 | 运算时需要 char↔int 转换 | 简单题目，代码量少 |
| **vector<int> 数字数组** | 运算高效，无需转换 | 需要反转，输出要转换 | 复杂运算，需要高效计算 |
| **char[] 字符数组** | C语言兼容，内存连续 | 需要手动管理，可能越界 | 对性能要求高的竞赛 |
| **int[] 数字数组** | 性能最高，控制精细 | 需要预分配固定大小 | 内存受限的环境 |

## 四、不同存储方式的实现对比

### 相同的加法逻辑，不同的存储方式：

**1. 用 vector<int> 存储：**
```cpp
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}
```

**2. 用 string 存储（低位在前）：**
```cpp
string add(const string& a, const string& b) {
    string result;
    int carry = 0;
    for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i] - '0';  // 多了 - '0'
        if (i < b.size()) sum += b[i] - '0';  // 多了 - '0'
        result.push_back((sum % 10) + '0');   // 多了 + '0'
        carry = sum / 10;
    }
    return result;
}
```

**看到区别了吗？**
- vector 版本：`result.push_back(sum % 10)` 直接存数字
- string 版本：`result.push_back((sum % 10) + '0')` 要转为字符

## 五、如何选择存储方式？

### 新手建议：
1. **从 string 开始**：理解算法逻辑
2. **过渡到 vector<int>**：提高代码效率
3. **掌握 char[]/int[]**：深入理解内存

### 选择标准：
| 标准 | 推荐存储方式 | 理由 |
|------|------------|------|
| **输入输出频繁** | string | 无需转换，直接使用 |
| **运算复杂** | vector<int> | 避免频繁类型转换 |
| **内存受限** | int[] | 静态分配，无额外开销 |
| **竞赛题** | vector<int> 或 int[] | 效率优先 |
| **学习理解** | string | 直观易懂 |

## 六、实际题目中的选择

### 题目1：P1009 阶乘之和
- 计算复杂：乘法、加法混合
- 推荐：vector<int> 或 int[]
- 理由：避免 char↔int 频繁转换

### 题目2：P1303 A*B Problem
- 只有乘法
- 都可以：string 或 vector<int> 都可以
- 简单就用 string，效率就用 vector<int>

### 题目3：P1601 A+B Problem
- 只有加法
- 推荐：string
- 理由：简单直观

## 七、混合使用技巧

你还可以混合使用不同存储方式：

```cpp
// 输入用 string，计算用 vector<int>，输出时再转回 string
string addStrings(string num1, string num2) {
    // 反转并转为数字数组
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    vector<int> a, b, result;
    for (char c : num1) a.push_back(c - '0');
    for (char c : num2) b.push_back(c - '0');
    
    // 计算
    int carry = 0;
    for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    // 转回字符串
    string ans = "";
    for (int i = result.size() - 1; i >= 0; i--) {
        ans += result[i] + '0';
    }
    
    return ans;
}
```

## 八、总结建议

1. **没有绝对的最佳选择**，只有最适合当前场景的选择
2. **学习阶段**：用 string 理解原理，用 vector<int> 提高效率
3. **竞赛阶段**：根据题目复杂度和个人习惯选择
4. **核心是理解算法**，存储方式只是实现工具

**给菜鸟的建议**：
- 先掌握一种（推荐 vector<int>），理解高精度本质
- 再尝试用不同方式实现，加深理解
- 最终形成自己的编码风格

记住：**高精度算法的核心是模拟手算**，存储方式只是帮助我们实现这个模拟过程的工具。理解算法逻辑比纠结存储方式更重要！


好，我直接用**ACM 最实用、最精简、最常用**的方式教你 `vector`，新手看完就能直接刷题用。
不讲废话，全是比赛里高频用法。

# 1. vector 是什么？
可以理解成：**会自动变长的数组**。
不用管大小，不用 malloc/free，不用 new/delete，非常安全。

# 2. 头文件
```cpp
#include <vector>
using namespace std;
```

# 3. 定义方式
```cpp
vector<int> a;          // 空的 int 数组
vector<int> a(n);       // 大小为 n，初始值都是 0
vector<int> a(n, 5);    // 大小为 n，每个元素都是 5
vector<vector<int>> a(n, vector<int>(m)); // n行m列二维数组
```

# 4. 最常用操作（ACM 90% 都用这些）
## 增
```cpp
a.push_back(x);   // 往末尾加元素 x
```

## 删
```cpp
a.pop_back();     // 删除最后一个元素
a.clear();        // 清空整个 vector
```

## 查/改
```cpp
a[i] = 10;        // 下标访问，和数组一样
a.at(i) = 10;     // 安全访问（越界会报错，比赛一般不用）
```

## 大小
```cpp
a.size();         // 元素个数
a.empty();        // 是否为空，空返回 true
```

## 遍历
```cpp
// 方法1（最常用）
for(int i=0; i<a.size(); i++)
    cout << a[i] << endl;

// 方法2（范围for）
for(int x : a)
    cout << x << endl;
```

# 5. ACM 高频用法示例

## 一维数组
```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
// v = [1,2,3]
```

## 二维数组（矩阵）
```cpp
int n = 3, m = 4;
vector<vector<int>> mat(n, vector<int>(m));

mat[0][1] = 5;
```

## 邻接表（图论必备）
```cpp
vector<int> g[100010];
g[u].push_back(v);
```

# 6. 必须记住的坑
1. `size()` 返回的是 **unsigned**，所以不要写：
   ```cpp
   for(int i=0; i<=v.size()-1; i++) // 空数组时 size()-1 会变成巨大数
   ```
   直接写：
   ```cpp
   for(int i=0; i<v.size(); i++)
   ```

2. 访问 `a[i]` 必须保证 `i < a.size()`，否则越界 RE。

# 7. 一句话总结
- `vector` = 安全、自动扩容的数组
- `push_back` 加元素
- `size()` 看大小
- `a[i]` 访问元素
- `vector<vector<int>>` 是二维数组

---

如果你愿意，我可以再给你：
- 一套 **ACM vector 速记 cheat sheet（一页纸）**
- 或者直接带你做一道最简单的 vector 入门题

你想要哪个？