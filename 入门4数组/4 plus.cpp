#include<bits/stdc++.h>
using namespace std;
bool tree[10002];
int main(){
    int m,l,sum=0;
    scanf("%d%d",&l,&m);
    for(int i=0;i<m;i++){
        int le,ri;
        scanf("%d%d",&le,&ri);
        for(int i=le;i<=ri;i++){
            if(tree[i]==0){//未被标记🦖
                sum++;
                tree[i]=1;//改成标记即可
            }
        }
    }
    printf("%d",l+1-sum);
    return 0;
}

//
//#include <bits/stdc++.h>
//using namespace std;
//int a[10000]
//int main(){
//    int l,m;
//    cin>>l>>m;
//    for(int i=0;i<m*2;i++){
//        cin>>a[i];
//    }
//
//    cout<<a+b<<endl;
//    return 0;
//}
//


