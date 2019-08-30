#include <iostream>
#include <queue>

using namespace std;

int home[52][52];
char vis[52][52];
int N,M;

char DIRECTION[] = {'E','S','W','N'};
int ex,ey;
struct Node
{
    int x,y;
    int step;
    int face;
    int turn;

    Node(){};
    Node(int x_, int y_, int step_, int face_, int turn_):x(x_),y(y_),step(step_),face(face_),turn(turn_){};

};

queue<Node> q;

void walk(int &dx, int &dy,int dir)
{
    if(dir == 0)
    {
        ++dy;
    }
    else if(dir == 1)
    {
        ++dx;
    }
    else if(dir == 2)
    {
        --dy;
    }
    else
    {
        --dx;
    }
}

bool canReach(int x, int y)
{
    if(x<1 || x>=N || y<1 || y>=M)
        return 0;

    if(home[x-1][y] || home[x][y] || home[x][y-1] || home[x-1][y-1])
        return 0;

    return 1;
}

int bfs()
{
    Node p;
    int face;
    int turn;
    int step;
    int x,dx;
    int y,dy;
    while(q.size())
    {
        p = q.front();
        q.pop();

        face = p.face;
        turn = p.turn;
        step = p.step;
        x = p.x;
        y = p.y;

        // move
        dx = x;dy = y;
        for(int i=1; i<=3; ++i)
        {
            walk(dx,dy,face);
            if(canReach(dx,dy))
            {
                if(dx == ex && dy == ey)
                {
                    return step+1;
                }
                if(!vis[dx][dy])
                {
                    q.push(Node(dx,dy,step+1,face,0));
                    vis[dx][dy] = 1;
                }

            }
            else
            {
                break;
            }
        }

        if(turn<2)
        {
            //Left
            q.push(Node(x,y,step+1,(face+3)%4, turn+1));
            //Right
            if(!turn)
                q.push(Node(x,y,step+1,(face+1)%4, 2));
        }

    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> home[i][j];
        }
    }

    int sx,sy;
    char face;
    cin >> sx >> sy >> ex >> ey;
    cin >> face;
    for(int i=0; i<4; ++i)
    {
        if(face == DIRECTION[i])
        {
            q.push(Node(sx,sy,0,i,0));
            break;
        }
    }

    vis[sx][sy] = 1;

    if(sx == ex && sy == ey)
        cout << 0;
    else
        cout << bfs();
}