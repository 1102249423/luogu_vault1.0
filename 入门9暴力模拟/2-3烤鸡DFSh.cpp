#include<bits/stdc++.h>
using namespace std;

const int maxn =13;//🦖只读证书，代码内不能修改该
char ans[100000+5];//🦖预留地址空间
char *anscur=ans;//🦖定义字符串指针变量anscur，把数组ans起始地址赋值给他。ans等价于ans【0】数组名直接代表数组首元素地址
int nums[maxn];//当前配料
int cnt =0;//表示方案总数
void printans() {
    for (int i = 0; i <10; ++i) {
        sprintf(ans+strlen(ans),"%d",nums[i]);//🦖ans等价于ans【0】，strlen表示数组长度，加上去表示末尾空地址。表示num拼接到数组末尾
    }
    sprintf(ans+strlen(ans),"\n");//每录十个加一个换行符
}

void dfs(int cur,int left) {//cur 表示正在甜第cur份配料，left表示还剩下几份配料
    if (cur==10&& !left) {//🦖感叹号是逻辑非-> "！+数字"的意思是：非零数字为false，零为true。
        //所以判断条件是如果用到第十份，并且剩余部分是0
        cnt++;//方案数+1
        printans();//将方案输入到字符里面
        return;//退出这一层
    }
    int &i=nums[cur];//&在变量前表示取地址，类后面表示别名
    for(i = 1; i <= 3; i++){
        if((10 - cur - 1) * 3 + i < left) continue;    // 剪枝。如果剩下的调料都加3克都不够，说明不可能
        if((10 - cur - 1) + i > left) break;        // 剪枝。如果剩下的调料都加一克也超量，说明不可能
        dfs(cur + 1, left - i);
    }
}
int main(){
    int n;
    scanf("%d", &n);

    if(10 <= n && n <= 30)
        dfs(0, n);
    printf("%d\n%s", cnt, ans); //输出答案
}
