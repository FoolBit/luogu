// Not my code
// I am too lazy
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,sum;
int ha[13],flag,yh[13][13];
bool v[13];
void print(){
    for(int i=1;i<=n;i++)
        printf("%d ",ha[i]);
}

void dfs(int step,int ans){
    if(ans>sum||flag)return;
    if(step==n+1&&ans==sum){
        print();
        flag=1;//标记
        return;
    }
    for(int i=1;i<=n;i++)
        if(!v[i]){
            ha[step]=i;
            v[i]=true;
            dfs(step+1,ans+i*yh[n][step]);//看顶楼的解释
            if(flag)
                return;
            v[i]=false;//回溯
        }
}

int main(){
    scanf("%d%d",&n,&sum);
    yh[1][1]=1;
    for(int i=2;i<=n;i++)//构造杨辉三角
        for(int j=1;j<=i;j++)
            yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
    dfs(1,0);
    return 0;
}