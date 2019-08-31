#include <iostream>
#include <cstring>

using namespace std;

char canvas[3000][3000];

int n,height,width;

void init()
{
    for(int i=0; i<height;++i)
    {
        for(int j=0; j<width; ++j)
            canvas[i][j] = ' ';
        canvas[i][width] = '\0';
    }
}

void paint(int sx, int sy, int depth)
{
    if(depth == 1)
    {
        canvas[sx][sy+1] = '/';
        canvas[sx][sy+2] = '\\';
        canvas[sx+1][sy] = '/';
        canvas[sx+1][sy+1] = '_';
        canvas[sx+1][sy+2] = '_';
        canvas[sx+1][sy+3] = '\\';
    }
    else
    {
        int unit = 1 << (depth-1);
        paint(sx, sy+unit, depth-1);
        paint(sx + unit, sy, depth-1);
        paint(sx+unit, sy+unit*2, depth-1);
    }
}
void print()
{
    for(int i=0; i<height; ++i)
        cout << canvas[i] << endl;
}

int main()
{
    cin >> n;
    height = 1<<n;
    width = height*2;
    init();
    paint(0,0,n);
    print();
}