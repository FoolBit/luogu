#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
    int h;
    point(int x_,int y_,int h_):x(x_),y(y_),h(h_){};
    bool operator <(const point &a)
    {
        return h<a.h;
    }
};

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int ans[101][101];

int main()
{
    int r,c;
    int x,y;
    int m[101][101];
    vector<point> p;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
        {
            scanf("%d",&m[i][j]);
            p.push_back(point(i,j,m[i][j]));
        }
    sort(p.begin(),p.end());
    int myMax=1;
    vector<point>::iterator it=p.begin();
    x=it->x;y=it->y;ans[x][y]=1;
    ++it;
#ifdef debug
#endif // debug
    for(;it!=p.end();++it)
    {
        x=it->x;y=it->y;
        bool flag=0;
        for(int i=0;i<4;++i)
        {
            if((x+dx[i]>=0)&&(x+dx[i]<r)&&(y+dy[i]>=0)&&(y+dy[i]<c))
             if(m[x+dx[i]][y+dy[i]]<m[x][y])
             {
                 flag=1;
                 if(ans[x][y]<ans[x+dx[i]][y+dy[i]]+1)
                     ans[x][y]=ans[x+dx[i]][y+dy[i]]+1;
                 if(ans[x][y]>myMax) myMax=ans[x][y];
             }
        }
        if(!flag) ans[x][y]=1;
    }
    printf("%d",myMax);
}