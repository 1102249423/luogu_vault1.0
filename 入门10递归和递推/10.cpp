//老爷版本可以抛弃了。学习要求研战结合才能获得成长，明显瓶颈就研究，无力气则战斗。
//#include <bits/stdc++.h>
//using namespace std;
//double s;
//double v;
//double time_min;
//double time_hour=0;
//int flag=0;
//int main(){
//    cin>>s>>v;
//    time_min=s/v+10;
//    if(time_min>=60){
//        time_min-=60;
//        time_hour++;
//        if(time_hour>=8){
//            flag=1;
//        }
//    }
//    if(flag==0){
//        time_min=60-time_min;
//        time_hour=7-time_hour;
//        //cout<<0<<time_hour<<":"<<fixed<<setprecision(0)<<time_min<<endl;
//        cout<<0<<time_hour<<":"<<int(time_min)<<endl;
//    }else{
//        time_min=60-time_min;
//        time_hour=time_hour-8;
//        time_hour=24-time_hour;
//        if(time_hour>=10){
//            cout<<time_hour<<":"<<int(time_min)<<endl;
//        }else{
//            cout<<0<<time_hour<<":"<<int(time_min)<<endl;
//        }
//    }
//    //cout<<fixed<<setprecision(1)<<p<<endl;
//    return 0;
//}

//是时候表演真正的技术了
//#include<bits/stdc++.h>
//using namespace std;
//double s,v,m;
//int n,a,t,b;
//int main(){
//    cin>>s>>v;
//    n=8*60+24*60;
//    t=ceil(s/v)+10;
//    n-=t;
//    if(n>=24*60)
//        n-=24*60;
//    b=n%60;
//    a=n/60;
//    printf("%02d:%02d",a,b);//记住，有可能要加0
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
double s;
double v;
int min_all;
int man_min;
int hour0,min0;
int main(){
    cin>>s>>v;
    min_all=8*60+24*60;
    man_min= ceil(s/v)+10;
    min_all=min_all-man_min;
    if(min_all>24*60){
        min_all-=24*60;
    }
    hour0=min_all/60;
    min0=min_all%60;
    printf("%02d:%02d",hour0,min0);//好用多了，c，c++语言都有
//    if(hour0>=10){
//        if(min0>=10){
//            cout<<hour0<<":"<<min0<<endl;
//        }else{
//            cout<<hour0<<":"<<0<<min0<<endl;
//        }
//    }else{
//        if(min0>=10){
//            cout<<0<<hour0<<":"<<min0<<endl;
//        }else{
//            cout<<0<<hour0<<":"<<0<<min0<<endl;
//        }
//    }

}