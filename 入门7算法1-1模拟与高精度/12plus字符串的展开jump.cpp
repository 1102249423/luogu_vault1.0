#include <bits/stdc++.h>
using namespace std;
int  p1,p2,p3;
string a;
int main(){
    cin>>p1>>p2>>p3;
    cin>>a;
    int len = a.size();
    for(int i = 0; i < len; ++i) {
        if(a[i] == '-' && a[i - 1] < a[i + 1] && ((a[i - 1] >= 'a' && a[i - 1] <= 'z' && a[i + 1] >= 'a' && a[i + 1] <= 'z') || (a[i - 1] >= '0' && a[i - 1] <= '9' && a[i + 1] >= '0' && a[i + 1] <= '9'))) {
            if(p1 == 1) {
                if(p3 == 2)//逆序
                    for(char j = a[i + 1] - 1; j >= a[i - 1] + 1; --j)
                        for(int k = 1; k <= p2; ++k)//p2重复几次
                            cout << j;
                else//正序
                    for(char j = a[i - 1] + 1; j <= a[i + 1] - 1; ++j)
                        for(int k = 1; k <= p2; ++k) {//p2重复几次
                            cout << j;
                        }
            } else if(p1 == 2) {
                if(p3 == 2)//逆序
                    for(char j = a[i + 1] - 1; j >= a[i - 1] + 1; --j)
                        for(int k = 1; k <= p2; ++k)//p2重复几次
                            //condition ? expression1 : expression2
                            //如果 condition为真，返回 expression1；如果 condition为假，返回 expression2
                            //printf("%c", (j >= 'a' && j <= 'z' ) ? j - 32 : j);//大写字母
                            cout << ((j >= 'a' && j <= 'z' ) ? j - 32 : j);
                else//正序
                    for(char j = a[i - 1] + 1; j <= a[i + 1] - 1; ++j)
                        for(int k = 1; k <= p2; ++k) {//p2重复几次
//								puts((j >= 'A') && (j <= 'Z') && (j > '9') ? "YES" : "NO");
                            //printf("%c", (j >= 'a' && j <= 'z' ) ? j - 32 : j);
                            cout << ((j >= 'a' && j <= 'z' ) ? j - 32 : j);
                        }
            } else if(p1 == 3) {//填充星星（blingbling）
                for(char j = a[i + 1] - 1; j >= a[i - 1] + 1; --j)
                    for(int k = 1; k <= p2; ++k)
                        cout << '*';
            }
        }else if(a[i] == '-' && a[i + 1] == a[i - 1] + 1)
            cout << a[i - 1] << a[i + 1];
        else
            cout << a[i];
    }
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
