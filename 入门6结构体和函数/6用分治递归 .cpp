
//分治
//该代码采用递归分治策略，默认整个矩阵所有元素初始为0（表示被赦免），
//然后递归地将不赦免的区域（即每次分割后的右上、左下、右下三个子矩阵）标记为1。
#include<stdio.h>
int n,ans[5555][5555];
 //x, y：当前子矩阵左上角在全局数组中的坐标（从0开始）。
 //n：当前子矩阵的阶数，其大小为2的n次
void dfs(int x,int y,int n)
{
    //即右上、左下、右下设为1。
    if(n==1){ans[x][y+1]=ans[x+1][y]=ans[x+1][y+1]=1;return;}
    //计算当前子矩阵的中心分界点：这里 1 << n-1即 2^n−1是子矩阵边长的一半。
    //然后将当前子矩阵分为四个大小相等的子矩阵，递归处理右上、左下、右下三个子矩阵（左上角子矩阵全部赦免，保持0不变）
     int midx=x+(1<<n-1),midy=y+(1<<n-1);//算出最中间的
    dfs(x,midy,n-1);   // 右上子矩阵
    dfs(midx,y,n-1);// 左下子矩阵
    dfs(midx,midy,n-1);// 右下子矩阵
}
int main()
{
    scanf("%d",&n);//输入
    dfs(0,0,n);
    for( int i=0;i<(1<<n);++i)
    {
        for( int j=0;j<(1<<n);++j)
            printf("%d ",ans[i][j]);//输出
        putchar('\n');
    }
}

/**
//该代码同样使用递归分治，但思路相反：首先将整个矩阵初始化为1（表示不赦免），然后递归地将每次分割的左上角子矩阵清零（设为0，表示赦免）。
#include <bits/stdc++.h>
using namespace std;
int n,o=1,a[1145][1145];
void dfs(int x,int l,int q){//三个参数意思分别是边长，以左上角为坐标原点的行数与列数。
	if(x==2){
		a[l][q]=0;
		return;
	}
	for(int i=l;i<=l+x/2-1;i++){
		for(int j=q;j<=q+x/2-1;j++){
			a[i][j]=0;
		}
	}
	dfs(x/2,l+x/2,q);
	dfs(x/2,l+x/2,q+x/2);
	dfs(x/2,l,q+x/2);
}
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		o*=2;
	}
	for(int i=1;i<=o;i++){
		for(int j=1;j<=o;j++){
			a[i][j]=1;
		}
	}
	dfs(o,1,1);
	for(int i=1;i<=o;i++){
		for(int j=1;j<=o-1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<a[i][o]<<endl;
	}
	return 0;
}

 */

