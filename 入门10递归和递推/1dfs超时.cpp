// #include <bits/stdc++.h>//🦖
// using namespace std;
// int N;
// int cnt;
// int bushu=0;
// void dfs(int step,int yibu,int liangbu) {
//     if(bushu==N) {
//         cnt++;
//         return;
//     }
//     bushu=(yibu+liangbu*2);
//     // yibu++;
//     dfs(step+1,yibu+1,liangbu);
//     dfs(step+1,yibu,liangbu+1);
//     //dfs(step+1,yibu+1,liangbu);
//
// }
// int main(){
//
//     cin>>N;
//     dfs(1,0,0);
//     cout<<cnt<<endl;
//     return 0;
// }
//画虎不成反类犬QAQ
#include <bits/stdc++.h>
using namespace std;
int N;
int cnt = 0;

// now：当前已经走完的台阶数
void dfs(int now)
{
    if (now == N)
    {
        cnt++;
        return;
    }
    if (now > N)
        return;
    // 选走1阶
    dfs(now + 1);
    // 选走2阶
    dfs(now + 2);
}

int main()
{
    cin >> N;
    dfs(0);
    cout << cnt << endl;
    return 0;
}