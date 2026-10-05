#include <bits/stdc++.h>
using namespace std;
double s;
double sum=0,mile=2,flag=0;
int main(){
    cin>>s;
    while (sum<s){
        sum+=mile;
        mile=mile*0.98;
        flag++;
    }
    cout<<flag<<endl;
    return 0;
}

