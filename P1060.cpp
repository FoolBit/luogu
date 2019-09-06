#include <iostream>
#include <cstring>

using namespace std;

int f[30002];
int N,m;

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> m;
    int w,v,p;
    while(m--)
    {
        cin >> v >> p;
        w = v*p;
        for(int i=N; i>=v; --i)
            f[i] = max(f[i],w+f[i-v]);
    }
    cout << f[N];
}