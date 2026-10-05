
#include <bits/stdc++.h>
using namespace std;
//string a;
int N;
long long B,sum;
long long cow[50000];
bool comp(long long x,long long y) {
    if (x!=y) {
        return x>y;
    }
    return false;
}
int main(){
    cin>>N;
    cin>>B;
    for (int i = 1; i < N+1; ++i) {
        cin>>cow[i];
    }
    sort(cow+1,cow+N+1,comp);
    int cnt=0;
    for (int i = 1; i <= N; ++i) {
        sum += cow[i];
        cnt++;
        if (sum >= B) break;
    }
    cout<<cnt<<endl;
    return 0;
}
