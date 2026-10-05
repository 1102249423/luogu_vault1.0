#include <iostream>
#include <vector>
using namespace std;

// 计算 n! 中数字 a 出现的次数
int countDigitInFactorial(int n, int digit) {
    // 特殊情况处理
    if (n == 0 || n == 1) {
        return (digit == 1) ? 1 : 0;  // 0! = 1! = 1
    }

    // 用 vector 存储大数，逆序存储（个位在[0]）
    vector<int> result = {1};  // 初始化为 1

    // 计算阶乘：从 2 乘到 n
    for (int i = 2; i <= n; i++) {
        int carry = 0;  // 进位

        // 大数乘法：result 的每一位乘以 i
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;  // 当前位
            carry = product / 10;       // 进位
        }

        // 处理剩余的进位
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // 统计数字 a 出现的次数
    int count = 0;
    for (int num : result) {
        if (num == digit) {
            count++;
        }
    }

    return count;
}

int main() {
    int t;  // 数据组数
    cin >> t;

    while (t--) {
        int n, a;
        cin >> n >> a;
        cout << countDigitInFactorial(n, a) << endl;
    }

    return 0;
}