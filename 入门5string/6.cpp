#include <bits/stdc++.h>
using namespace std;
int q;
string str;
int k;

string str2;
int a,b;
int c;
string str3;
string str4;
int main(){
    cin>>q;
    cin>>str;
    for (int i = 1; i <= q; i++) {
        cin>>k;
        if(k==1){//后接插入，在文档后面插入字符串 str，并输出文档的字符串；
            cin>>str2;
            //🦖插入不会写
            str += str2;
            cout << str << endl;
        }else if(k==2){//截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串；
            cin>>a>>b;
            str = str.substr(a, b);
            cout<<str<<endl;
        }else if(k==3){//插入片段，在文档中第 a 个字符前面插入字符串 str，并输出文档的字符串；
            cin>>c;
            cin>>str3;
            //🦖插入不会写
            str.insert(c, str3);
            cout << str << endl;
        }else if(k==4){//查找子串，查找字符串 str 在文档中最先的位置并输出；如果找不到输出 −1。
            cin>>str4;
            int tmp = str.find(str4);
            if (tmp == string::npos)
                cout << -1 << endl;
            else
                cout << tmp << endl;
        }
    }
}


















//
//
//
//#include<stdio.h>
//#include<string.h>
//#define MAXN 101
//char str[MAXN], in[MAXN];
//int main(void)
//{
//    int q;
//    scanf("%d\n%s", &q, str);
//    for (int i = 1; i <= q; i++) {
//        int opt;
//        scanf("%d", &opt);
//        if (opt == 1) {
//            scanf("%s", in);
//            strcat(str, in);
//            printf("%s\n", str);
//        }
//        else if (opt == 2) {
//            int a, b;
//            scanf("%d %d", &a, &b);
//            str[a + b] = '\0';
//            strcpy(in, &str[a]);
//            strcpy(str, in);
//            printf("%s\n", str);
//        }
//        else if (opt == 3) {
//            int a;
//            scanf("%d %s", &a, in);
//            strcat(in, &str[a]);
//            str[a] = '\0';
//            strcat(str, in);
//            printf("%s\n", str);
//        }
//        else {
//            scanf("%s", in);
//            char *ans = strstr(str, in);
//            printf("%d\n", ans != NULL ? (int)(ans - str) : -1);
//        }
//    }
//    return 0;
//}
