#include<iostream>
#include<cmath>
using namespace std;
int a[31],i=0,j;
long long s=0;
int main(){
    //🦖当没有上界的时候，读取你输入的所有数字，存在数组a里，i是数字的总个数
    //其中 while(cin>>C) 这一语法利用了 cin 的特性，当 cin 没能读入到信息的时候，会返回 0，那么循环就会终止。
    while(cin>>a[i++]);//合写cin>>a[i];i++;
    for(j=0;j<i;j++){
        s+=a[j];
    }
    s*=pow(2,i-2);//pow(2, k) 是数学里的 2 的 k 次方（数学优化每个数字取了2^n-1次）
    cout<<s;
    return 0;
}

