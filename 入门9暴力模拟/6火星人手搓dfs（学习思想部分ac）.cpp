#include <bits/stdc++.h>
using namespace std;

int n, m;
int start[15];
int res[15];
bool vis[15];
long long cnt = 0;
long long target;
long long pos = 0; // 用来及时保存初始排列序号
bool found = false;

bool equal()
{
    for(int i=1;i<=n;i++)
        if(res[i] != start[i])
            return false;
    return true;
}

void dfs(int step)
{
    if(found) return;
    if(step > n)
    {
        cnt++;
        // 重点：第一次找到初始排列立刻记录pos
        if(pos == 0 && equal())
        {
            pos = cnt;
        }
        if(cnt == target)
        {
            for(int i=1;i<=n;i++)
                cout << res[i] << " ";
            found = true;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            res[step] = i;
            dfs(step+1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> start[i];

    dfs(1);  //第一轮搜索，dfs内部自动捕获pos

    memset(vis,0,sizeof vis);
    cnt = 0;
    found = false;
    target = pos + m;
    dfs(1);
    return 0;
}