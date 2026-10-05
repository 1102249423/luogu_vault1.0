//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    if(n==0){
//        cout<<0<<endl;
//    }else if(n>0){
//        string s= to_string(n);
//        string s1=s;
//        int left = 0, right = s.size() - 1;
//        int flag=right+1;
//        for(int i=right;i>=0;i--){
//            if(s1[i]=='0'){
//                flag=i;
//            }else{
//                break;
//            }
//        }
//        if(flag==right+1){
//            int flag1=right;
//            for(int i=0;i<=flag1;i++){
//                s1[i]=s[flag1];
//                flag1=flag1-1;
//            }
//            for(int i=0;i<=flag1;i++){
//                cout<<s1[i];
//            }
//        }else{
//            int flag2=flag-1;
//            for(int i=0;i<=flag-1;i++){
//                s1[i]=s[flag2-1];
//                flag2=flag2-1;
//            }
//            for(int i=0;i<=flag-1;i++){
//                cout<<s1[i];
//            }
//        }
//
//
//    }else if(n<0){
//        n=-n;
//        string s= to_string(n);
//        string s1=s;
//        int left = 0, right = s.size() - 1;
//        int flag=s.size() - 1;
//
//        for(int i=right;i>=0;i--){
//            if(s1[i]=='0'){
//                flag=i;
//            }else{
//                break;
//            }
//        }
//        //cout<<flag<<endl;
//        int flag1=flag;
//        for(int i=0;i<=flag;i++){
//            s1[i]=s[flag1];
//            flag1=flag1-1;
//        }
//        cout<<'-';
//        for(int i=1;i<=flag;i++){
//            cout<<s1[i];
//        }
//    }
//    return 0;
//}
//纯纯的垃圾思路ψ(*｀ー´)ψ[恶心][恶心][呕吐][呕吐]


#include <bits/stdc++.h>
using namespace std;
//s[11]：长度为11的long long数组，初始化全部为0。代码中只使用s[1]到s[10]，用于存储n的每一位数字。
//n：存储输入的正整数。
//k：初始化为0，用于存储反转后的数字.
//a：初始化为1，在第一个循环中用于提取n的每一位。
long long s[11]={},n,k=0,a=1;
int main()
{
    memset(s,0, sizeof(n));
    cin>>n;
    for (int i = 0; i <=10 ; i++) {
        s[i]=n/a%10;//🦖个 十 百 千
        a*=10;//🦖个 十 百 千
    }
    a=1000000000;//重新将a初始化为10^9
    for(int i=1;i<=10;i++) k+=s[i]*a,a/=10;//循环10次，每次将s[i]乘以当前的a并加到k上，然后a除以10。
    while(k%10==0) k/=10;//倒着看，最后有0就除掉，mmp人机一句话就解决了ψ(*｀ー´)ψ
    cout<<k;//输出不解释
    return 0;
}


//string
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main()//不解释
{
    cin>>s1;
    if(s1[0]=='-')
    {
        cout<<"-";//输出负号
        for(int i=s1.length()-1,j=0;i>=1;i--,j++) s2=s2+s1[i];//倒着变成正的（好烦）
        //find_first_not_of('0')：返回s2中第一个不是字符'0'的位置
        //erase(0, pos)：从位置0开始，删除pos个字符
        //效果：删除开头的所有零字符
        if(s2[0]=='0') s2.erase(0,s2.find_first_not_of('0'));//去0
        cout<<s2;//输出
    }
    else //否则为正
    {
        for(int i=s1.length()-1,j=0;i>=0;i--,j++) s2=s2+s1[i];//正着倒序（还是好烦吧）
        if(s2[0]=='0')s2.erase(0,s2.find_first_not_of('0'));//删除0
        cout<<s2;//输出
    }
    return 0;//终于结束了
}


#include <bits/stdc++.h>
using namespace std;
char a[100001];
int t=0;
int main()
{
    string b,c;
    bool sign=false,flag=false;
    cin>>c;
    for(int i=0;i<=c.length();i++)
    {
        if(c[i]=='-') s=true;
        else a[++t]=c[i];
    }
    if(s==true)    b+="-";
    t--;
    for(t;t>=0;t--)
    {
        if(a[t]!='0'&&f==false) f=true,b+=a[top];
        else if(f==true) b+=a[t];
    }
    int i=atoi(b.c_str());
    cout<<i;
    return 0;
}































