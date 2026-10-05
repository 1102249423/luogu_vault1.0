#include <bits/stdc++.h>
using namespace std;
int n;
int k1=1,k2=1;
int flag_empty;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(k1<10){
                cout<<0<<k1;
            }else{
                cout<<k1;
            }
            k1++;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<"  ";
    }
    cout<<endl;
    for(int l=0;l<n;l++){
        flag_empty=n-1-l;
        while(flag_empty>0){
            flag_empty--;
            cout<<"  ";

        }

//        for(flag_empty=n-1-l;flag_empty!=0;flag_empty--){
//            cout<<"  ";
//            flag_empty--;
//        }
        for(int m=0;m<=l;m++){
            if(k2<10){
                cout<<0<<k2;
            }else{
                cout<<k2;
            }
            k2++;
            if(m==l){
                cout<<endl;
            }
        }
    }
    return 0;
}

