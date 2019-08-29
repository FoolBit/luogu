#include <iostream>

using namespace std;

int n;
int square[31][31];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return;
    square[x][y] = 2;
    for(int i=0; i<4; ++i)
    {
        int dx = x+dir[i][0];
        int dy = y+dir[i][1];
        if(!square[dx][dy])
            dfs(dx,dy);
    }
}
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin >> square[i][j];
        }
    }

    for(int i=0; i<n; ++i)
    {
        if(!square[0][i])
            dfs(0,i);
        if(!square[i][0])
            dfs(i,0);
        if(!square[n-1][i])
            dfs(n-1,i);
        if(!square[i][n-1])
            dfs(i,n-1);
    }

    for(int i=0;i<n;++i)
    {
        cout << 2-square[i][0];
        for(int j=1; j<n; ++j)
        {
            cout << ' ' << 2-square[i][j];
        }
        cout << endl;
    }
}