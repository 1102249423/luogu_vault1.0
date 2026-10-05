#include <bits/stdc++.h>
using namespace std;

int leicheng(int x){
    //🦖
    //int x;
    if(x==0){
        return 1;
    }else{
        return leicheng(x-1)*x;
    }
}
int main(){
    int n;
    cin>>n;
    cout << leicheng(n) << endl;
    return 0;
}
