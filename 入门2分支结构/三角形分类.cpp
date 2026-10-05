#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){

    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&c+b>a){
        if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
            cout<<"Right triangle"<<endl;
        }
        if(a*a+b*b>c*c&&a*a+c*c>b*b&&b*b+c*c>a*a){
            cout<<"Acute triangle"<<endl;
        }
        if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a){
            cout<<"Obtuse triangle"<<endl;
        }
        if(a==b||a==c||b==c){
            cout<<"Isosceles triangle"<<endl;
        }
        if(a==b&&b==c){
            cout<<"Equilateral triangle"<<endl;
        }



    }else{
        cout<<"Not triangle"<<endl;
    }

    cout<<endl;
    return 0;
}