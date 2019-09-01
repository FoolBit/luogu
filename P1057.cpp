#include <iostream>
using namespace std;

int f[31][31];
int n,m;

int notdp(int i, int depth)
{
    if(f[i][depth]!=-1)
        return f[i][depth];

    f[i][depth] = notdp((i+1)%n,depth-1) + notdp((i+n-1)%n,depth-1);

    return f[i][depth];
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        for(int j=1;j<=m;++j)
        {
            f[i][j] = -1;
        }
    }
    f[0][0] = 1;
    cout << notdp(0,m);
}