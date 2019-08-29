#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct Node
{
    int x,y;
    int step;
    Node(int x_, int y_, int step_):x(x_),y(y_),step(step_){};
};

queue<Node> q;

int board[401][401];
bool vis[401][401];
int dir[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int n,m;
bool legal(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
        return 0;
    return 1;
}
void bfs()
{
    while(q.size())
    {
        Node node = q.front();
        q.pop();

        int x,y,step;
        x = node.x;y=node.y;step=node.step;

        if(vis[x][y])
            continue;
        vis[x][y] = 1;
        board[x][y] = step;

        for(int i=0; i<8; ++i)
        {
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];

            if(legal(dx,dy))
                q.push(Node(dx,dy,step+1));
        }

    }
}

int getStep(int x,int y)
{
    if(!vis[x][y])
        return -1;
    return board[x][y];
}

void print()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("%-5d",getStep(i,j));
        }
        printf("\n");
    }
}



int main()
{
    int x,y;
    cin >> n >> m >> x >> y;
    q.push(Node(x,y,0));
    bfs();
    print();
}