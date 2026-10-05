#include <bits/stdc++.h>//🦖nlogn
using namespace std;
int n,m;
priority_queue<int,vector<int>,greater<int> > q;//定义小根堆
int main(){
    cin>>n>>m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin>>x;
        q.push(x);
    }
    while (q.size()>0) {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}

