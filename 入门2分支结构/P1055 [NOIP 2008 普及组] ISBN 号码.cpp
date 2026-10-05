//主要问题在输入流的问题上怎么分析，有两种策略
//1采用scanf来看。必须手动计算数组长度（设小了会溢出，设大了浪费）；
#include <stdio.h>
#include <string.h> // 用strlen等字符串函数需要这个头文件

int main() {
    // 定义字符数组，长度14（13个有效字符 + 1个'\0'）
    char isbn[14];
    // 用scanf读取输入的ISBN字符串，存入数组，数组不需要地址本身就代表地址
    scanf("%s", isbn);

    // 1. 提取前9位数字（跳过分隔符'-'）
    int nums[9];
    int idx = 0;
    for (int i = 0; i < strlen(isbn); i++) { // 遍历数组每个字符
        if (isbn[i] == '-') continue; // 跳过分隔符
        if (idx < 9) { // 只取前9个数字
            nums[idx++] = isbn[i] - '0'; // 字符转数字
        } else {
            break;
        }
    }

    // 2. 计算加权和
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += nums[i] * (i + 1);
    }

    // 3. 计算正确识别码
    int mod = sum % 11;
    char correct_check;
    if (mod == 10) {
        correct_check = 'X';
    } else {
        correct_check = mod + '0';
    }

    // 4. 提取输入的识别码（数组最后一位：arr[12]）
    char input_check = isbn[12];

    // 5. 验证并输出
    if (input_check == correct_check) {
        printf("Right\n");
    } else {
        // 替换最后一位为正确识别码
        isbn[12] = correct_check;
        printf("%s\n", isbn);
    }

    return 0;
}

//2string是 C++ 标准库提供的 “字符串类”，可以理解为 “智能字符数组”，搭配cin读取输入，不用操心长度问题。
//cin >> isbn：直接读取字符串，用法和scanf类似（忽略空白符）；
//便捷操作：
//isbn.back()：直接获取最后一位字符（不用算下标，对应 ISBN 的识别码）；
//isbn.size()：获取字符串长度；
//isbn[i]：也支持下标访问，和数组一样；
//直接替换字符：isbn[isbn.size()-1] = correct_check。

//
//
//#include <iostream>
//#include <string> // 使用string必须包含这个头文件
//using namespace std;
//
//int main() {
//    string isbn; // 定义string变量，无需指定长度
//    cin >> isbn; // 读取输入，自动适配长度
//
//    // 1. 提取前9位数字
//    int nums[9];
//    int idx = 0;
//    for (char c : isbn) { // 范围for循环，遍历每个字符（C++11及以上支持）
//        if (c == '-') continue;
//        if (idx < 9) {
//            nums[idx++] = c - '0';
//        } else {
//            break;
//        }
//    }
//
//    // 2. 计算加权和
//    int sum = 0;
//    for (int i = 0; i < 9; i++) {
//        sum += nums[i] * (i + 1);
//    }
//
//    // 3. 计算正确识别码
//    int mod = sum % 11;
//    char correct_check;
//    if (mod == 10) {
//        correct_check = 'X';
//    } else {
//        correct_check = mod + '0';
//    }
//
//    // 4. 提取输入的识别码（直接用back()）
//    char input_check = isbn.back();
//
//    // 5. 验证并输出
//    if (input_check == correct_check) {
//        cout << "Right" << endl;
//    } else {
//        string correct_isbn = isbn;
//        correct_isbn[correct_isbn.size() - 1] = correct_check;
//        cout << correct_isbn << endl;
//    }
//
//    return 0;
//}