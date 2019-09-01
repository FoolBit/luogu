#include <iostream>

using namespace std;

int f[1001][1001];
int R;
int MAX;

int main()
{
    cin >> R >> f[0][0];
    MAX = f[0][0];
    for(int i=1; i<R; ++i)
    {
        cin >> f[i][0];
        f[i][0]+=f[i-1][0];
        MAX = max(f[i][0],MAX);

        for(int j=1;j<i+1;++j)
        {
            cin >> f[i][j];
            f[i][j] += max(f[i-1][j-1],f[i-1][j]);
            MAX = max(f[i][j],MAX);
        }
    }
    cout << MAX;
}