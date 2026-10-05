//前面两道题都是string输入然后处理的。
//这里用数组存放内容进行处理
#include <iostream>
#include <vector>
using namespace std;

// 高精度乘法：大整数 a 乘以整数 b
vector<int> multiply(const vector<int>& a, int b) {
    vector<int> c;
    int carry = 0;

    for (int i = 0; i < a.size(); i++) {
        int temp = a[i] * b + carry;
        c.push_back(temp % 10);
        carry = temp / 10;
    }

    while (carry) {
        c.push_back(carry % 10);
        carry /= 10;
    }

    return c;
}

// 高精度加法：大整数 a 加上大整数 b
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int carry = 0;
    int i = 0;

    while (i < a.size() || i < b.size() || carry) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];

        c.push_back(sum % 10);
        carry = sum / 10;
        i++;
    }

    return c;
}

int main() {
    int n;
    cin >> n;

    // 初始化：当前阶乘 fact = 1! = 1，总和 sum = 0
    vector<int> fact(1, 1);  // 包含一个元素，值为1
    vector<int> sum(1, 0);   // 包含一个元素，值为0

    // 计算 1! 到 n! 的和
    for (int i = 1; i <= n; i++) {
        fact = multiply(fact, i);  // 计算 i!
        sum = add(sum, fact);      // 累加到总和
    }

    // 输出结果（注意要逆序输出，因为存储是低位在前）
    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}



//string

/*
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
*/
















