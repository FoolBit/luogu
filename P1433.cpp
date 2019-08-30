#include <iostream>
#include <map>
#include <iomanip>
#include <bitset>
#include <cmath>
using namespace std;

int n;
float points[16][2];
float dis[16][16];
char vis[16];
float mincost = 0x3f3f3f3f;

void dfs(int depth, int pos, float cost);
float distance(int a,int b);

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> points[i][0] >> points[i][1];
    }

    for(int i=0; i<=n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
            float dis_ = distance(i,j);
            dis[i][j] = dis_;
            dis[j][i] = dis_;
        }
    }

    dfs(0,0,0);

    cout << setiosflags(ios::fixed) << setprecision(2) << mincost;
}

float distance(int a,int b)
{
    float x1 = points[a][0];
    float y1 = points[a][1];

    float x2 = points[b][0];
    float y2 = points[b][1];

    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

void dfs(int depth, int pos, float cost)
{
    if(cost >= mincost)
        return;
    if(depth == n)
    {
        mincost = cost;
        return;
    }

    vis[pos] = 1;

    for(int i=1; i<=n; ++i)
    {
        if(!vis[i])
        {
            dfs(depth+1, i, cost+dis[pos][i]);
        }
    }

    vis[pos] = 0;
}