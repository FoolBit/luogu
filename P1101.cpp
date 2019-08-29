#include <iostream>
#include <cstring>

using namespace std;

int N;
char square[102][102];
char highLightSquare[102][102];

int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
char word[] = "yizhong";

int found;

void dfs(int x,int y,int pos, int direction)
{
    if(pos == 7)
    {
        found = 1;
        return;
    }
    if(x<0 || x>=N || y<0 || y>=N)
        return;

    if(square[x][y] == word[pos])
    {
        dfs(x+dir[direction][0],y+dir[direction][1],pos+1,direction);
        if(found)
            highLightSquare[x][y] = 1;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
            cin >> square[i][j];
    }

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(square[i][j]=='y')
            {
                for(int k=0; k<8; ++k)
                {
                    found = 0;
                    dfs(i+dir[k][0],j+dir[k][1],1,k);
                    if(found)
                        highLightSquare[i][j] = 1;
                }
            }
        }
    }

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(highLightSquare[i][j])
            {
                cout << square[i][j];
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }

}