////【P1553】数字反转（升级版） - 洛谷 - 100
//#include<bits/stdc++.h>
////using namespace std;  // 使用标准命名空间
//// 自己写的反转函数，返回反转并去掉前导零之后的字符串
//string reverse(string s) {
//    int zeroCount = 0;
//    reverse(s.begin(), s.end()); // 反转
//    // 范围 for 循环，用于统计前导零个数
//    for (auto i : s)
//        if (i == 48) ++zeroCount;
//        else break;
//    s.erase(s.begin(), s.begin() + zeroCount);
//    return (s != "" ? s : "0"); // 特判
//}
//
//// 用于去掉后导零
//string deleteTail(string s) {
//    int zeroCount = 0;
//    for (int i = s.size() - 1; i >= 0; --i)
//        if (s[i] == 48) ++zeroCount;
//        else break;
//    s.erase(s.end() - zeroCount, s.end());
//    return (s != "" ? s : "0");
//}
//
//int main() {
//    string s;
//    cin >> s;
//    if (s.back() == '%') {
//        cout << reverse(s.substr(0, s.size() - 1)) << "%" << endl;
//        return 0;
//    }
//    for (auto i : s) {
//        string left, right;
//        // 其实还有一种不需要遍历字符串的做法，直接 find() 即可，但是当时没想到
//        if (i == '/') {
//            left = s.substr(0, s.find("/"));
//            right = s.substr(s.find("/") + 1);
//            cout << reverse(left) << "/" << reverse(right) << endl;
//            return 0;
//        }
//        if (i == '.') {
//            left = s.substr(0, s.find("."));
//            right = s.substr(s.find(".") + 1);
//            cout << reverse(left) << "." << deleteTail(reverse(right)) << endl;
//            return 0;
//        }
//    }
//    // 最后剩下的一种情况是正整数
//    cout << reverse(s) << endl;
//    return 0;
//}




#include<bits/stdc++.h>
using namespace std;  // 使用标准命名空间
// 自己写的反转函数，定义反转函数，参数为字符串s，返回反转并去掉前导零之后的字符串
string reverse1(string s) {
    int zeroCount = 0;  // 计数器，用于统计前导零个数
    // 使用reverse函数反转整个字符串
    // s.begin()返回字符串起始迭代器
    // s.end()返回字符串结束迭代器
    reverse(s.begin(), s.end());
    // 范围 for 循环，用于统计前导零个数
    for (auto i : s) // 范围for循环，遍历反转后的字符串
        if (i == 48) ++zeroCount; // 48是字符'0'的ASCII码，统计连续零
        else break;// 遇到非零字符立即停止统计
    s.erase(s.begin(), s.begin() + zeroCount);// 删除前导零
    return (s != "" ? s : "0"); // 三元运算符：若非空返回s，否则返回"0"
}

string deleteTail(string s) { // 定义删除尾部零函数
    int zeroCount = 0; // 尾部零计数器
    for (int i = s.size() - 1; i >= 0; --i)// 从后向前遍历字符串
        if (s[i] == 48) ++zeroCount;  // 统计连续的零字符
        else break; // 遇到非零字符停止
    s.erase(s.end() - zeroCount, s.end()); // 删除尾部零
    return (s != "" ? s : "0"); // 处理全零情况
}

int main() {
    string s;
    cin >> s;
    if (s.back() == '%') {// s.back()返回字符串最后一个字符的引用
        cout << reverse1(s.substr(0, s.size() - 1)) << "%" << endl;
        // substr(0, s.size()-1)获取从0开始、长度为size()-1的子串
        // 即去掉百分号的部分
        return 0;//over
    }
    for (auto i : s) {// 遍历字符串每个字符
        string left, right;
        // 其实还有一种不需要遍历字符串的做法，直接 find() 即可，但是当时没想到
        if (i == '/') {
            // 获取斜杠前的子串
            left = s.substr(0, s.find("/")); // s.find("/")返回斜杠第一次出现的位置
            // 获取斜杠前的子串
            right = s.substr(s.find("/") + 1);
            cout << reverse1(left) << "/" << reverse1(right) << endl;
            return 0;
        }
        if (i == '.') {
            // 获取小数点前部分
            left = s.substr(0, s.find("."));
            // 获取小数点后部分
            right = s.substr(s.find(".") + 1);
            // 对小数部分先反转，再去掉反转后的尾部零
            cout << reverse1(left) << "." << deleteTail(reverse1(right)) << endl;
            return 0;
        }
    }
    // 最后剩下的一种情况是正整数
    cout << reverse1(s) << endl;
    return 0;
}
