#include <bits/stdc++.h>
using namespace std;

int main(){
    int coins=0,day=0,flag=0,sum=0;
    int a,b;
    cin>>day;
    a=b=1;//b来记录第几天，a记录层数
    for(int i=1;i<=day;i++){
        coins+=a;
        b--;
        if(b==0){
            a++;
            b=a;
        }
    }
    cout<<coins<<endl;
    return 0;
}