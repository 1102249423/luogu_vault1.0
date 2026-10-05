//int 最大约 21 亿（10 位），long long 最大约 9e18（19 位）；
//50! ≈ 3.04×10⁶⁴（65 位），必须用高精度算法（数组存储每一位数字，模拟手工计算）。

//trash
//#include <bits/stdc++.h>
//using namespace std;
//double n;
//double S,s1=1;
//int main(){
//    //int a,b;
//    cin>>n;
//    for(double i=n;i>=1;i--){
//        for(double j=i;j>=1;j--){
//            s1=s1*j;
//        }
//        S=S+s1;
//        s1=1;
//    }
//    cout<<S<<endl;
//    return 0;
//}

//用数组模拟大数（高精度运算），解决阶乘和的溢出问题，核心操作是高精度乘法（计算阶乘）和高精度加法（累加阶乘和）
//这个过程有点像单片机处理数据那个过程。只不过数码管变成了维度高的数组。
#include <bits/stdc++.h>
using namespace std;
int n;
//因为1!+2!+...+20!的位数不足 90 位，数组用90代替大小。
int a[90];//临时存储当前要参与乘法的数 i（逆序存储，比如 i=123，a 中存 [3,2,1]）；
int b[90];//存储上一个阶乘的结果（即(i−1)!，同样逆序存储），作为乘法的 “基数”
int c[90];//乘法的临时结果数组，存储 a*b（即i∗(i−1)!）的中间结果，用完即清零.
int f[90];//存储阶乘的累加和（1!+2!+...+i!），最终结果也存在这个数组中（逆序）
int lena=1,lenb=1,lenc=1;
int len_ans;
int m;
int main(){
    cin>>n;
    b[0]=1;
    for(int i=1;i<=n;i++){
        lena=0;//数组长度
        int p=i;//设置一个替身
        while (p>0){
            a[lena++]=p%10;//两步骤 1先把...的结果存入a数组的「当前len_a下标位置」，2再将len_a的值加 1
            p/=10;
        }
        for (int j = 0; j <lena ; j++) {
            for (int k = 0; k < lenb; k++) {
                c[k+j]+=a[j]*b[k];
            }
        }
        for (int j = 0; j <lenc; j++) {
            if(c[j]>9){
                c[j+1]+=c[j]/10;
                c[j]%=10;
            }
        }

        if(c[lenc]) {//如果括号内的变量值「不等于 0」，条件为真，执行后续语句；如果变量值「等于 0」，条件为假，不执行后续语句。
            lenc++;//如果lenc需要进位，则修改长度0-4则长度改为5；
        }
        len_ans=lenb;
        lenb=lenc;
        m=max(m,lenc); //把len_b赋值给len_ans，修改len_b的值，m为i阶乘的长度，看有没有进位
        for (int k = lenc-1; k >=0 ; k--) {
            b[k]=c[k];
            lenc=lena+lenb;
        }
        memset(c,0,sizeof(c)); //清零c数组，准备计算下个阶乘
        //// 替代 memset(c,0,sizeof(c)); 的手动清零写法
        //for(int i=0; i<90; i++) {
        //    c[i] = 0; // 逐个将 c 数组的元素置为 0
        //}
        for(int j=0;j<m;j++){ //高精加，直接套模板
            f[j]+=b[j];
            if(f[j]>9) {
                f[j+1]+=f[j]/10;
                f[j]%=10;
            }
        }

    }
    while(!f[m]&&m>0)
        m--; //去掉首导零
    for(int i=m;i>=0;i--){
        cout<<f[i]; //倒序输出
    }
    return 0;

}

