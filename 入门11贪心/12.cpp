#include <bits/stdc++.h>
using namespace std;
double a;
double b;
double c;
double d;
double t1,t2,t;
int min0,hour0;
int main(){
    cin>>a>>b>>c>>d;
    t2=c*60+d;
    t1=a*60+b;
    t=t2-t1;
    min0=int(t)%60;
    hour0=int(t)/60;
    //p=((a+b+c))/2;
    //s=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<hour0<<" "<<min0<<endl;
    //cout<<fixed<<setprecision(1)<<s<<endl;
    return 0;
}
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a,b,c,d;
//    cin>>a>>b>>c>>d;
//    int x=c-a,y=d-b;
//    if(y<0){x--;y+=60;}
//    cout<<x<<" "<<y;
//    return 0;
//}
