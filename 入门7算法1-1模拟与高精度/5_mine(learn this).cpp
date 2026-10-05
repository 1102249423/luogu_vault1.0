#include <bits/stdc++.h>
using namespace std;
string s1,s2;
signed main(){
    cin>>s1>>s2;

    if (s1 == "0" || s2 == "0") {
        cout << 0 << endl;
        return 0;
    }
    // reverse(开始位置, 结束位置)：反转指定范围内的元素
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    // 获取字符串长度
    int len1 = s1.length();
    int len2 = s2.length();

    // 使用 vector 代替普通数组，可以动态调整大小
    // vector<int> result(len1 + len2, 0) 创建大小为 len1+len2 的 vector，全部初始化为0
    vector<int> result(len1 + len2, 0);

    // 乘法计算
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            // 注意：这里和下面对应
            // 原来：c[i+j-1] += a[j] * b[i]
            // 现在：result[i+j] += (s1[i]-'0') * (s2[j]-'0')
            // 因为数组下标从1改为从0开始，所以是 i+j
            result[i + j] += (s1[i] - '0') * (s2[j] - '0');
        }
    }
    // 处理进位
    for (int i = 0; i < len1 + len2 - 1; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;  // 进位
            result[i] %= 10;  // 保留个位
        }
    }

    // 找到最高位（去掉前导0）
    int len = result.size();  // 获取vector的大小
    while (len > 1 && result[len - 1] == 0) {
        len--;  // 如果最高位是0，就减少长度
    }

    // 从高位到低位输出
    for (int i = len - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}