#include <iostream>

using namespace std;

int N,M;
char haze[1002][1002];
int vis[1002][1002];
int cnt;
int nblocks;
int ans[1000005];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y,char c)
{
    if(x<1 || x>N || y<1 || y>N)
        return;
    if(haze[x][y] == c)
        return;
    if(vis[x][y])
        return;
    vis[x][y] = cnt;
    ++nblocks;
    for(int i=0; i<4; ++i)
    {
        dfs(x+dir[i][0], y+dir[i][1], haze[x][y]);
    }

}

void process()
{
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            if(!vis[i][j])
            {
                ++cnt;
                nblocks = 0;
                dfs(i,j,'1' + '0' - haze[i][j]);
                ans[cnt] = nblocks;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1;i<=N;++i)
    {
        for(int j=1; j<=N;++j)
        {
            cin >> haze[i][j];
        }
    }

    process();

    for(int i=0; i<M; ++i)
    {
        int x,y;
        cin >> x >> y;
        int type = vis[x][y];
        cout << ans[type] << endl;
    }

}