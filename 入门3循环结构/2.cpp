
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int counta=0,countb=0;
    double suma=0.0,sumb=0.0;
    for(int i=1;i<=n;i++){
        if(i%k==0){
            counta++;
            suma+=i;
        }else{
            countb++;
            sumb+=i;
        }
    }
    suma=suma/counta;
    sumb=sumb/countb;
    cout << fixed << setprecision(1) << suma << " ";
    cout << fixed << setprecision(1) << sumb << endl;

}