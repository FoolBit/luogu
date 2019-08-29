#include <iostream>

using namespace std;

int N,M,T;
int haze[6][6];
int sx,sy,fx,fy;
int cnt;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y)
{
    if(x<1 || x>N || y<1 || y>M)
        return;
    if(haze[x][y])
        return;
    if(x == fx && y == fy)
    {
        ++cnt;
        return;
    }
    
    haze[x][y] = 1;
    for(int i=0; i<4; ++i)
    {
        dfs(x+dir[i][0],y+dir[i][1]);
    }
    haze[x][y] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M >> T;
    cin >> sx >> sy >> fx >> fy;

    for(int i=0; i<T; ++i)
    {
        int x,y;
        cin >> x >> y;
        haze[x][y] = 1;
    }

    dfs(sx,sy);

    cout << cnt;
}