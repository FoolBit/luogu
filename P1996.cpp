#include <iostream>

using namespace std;

int vis[102];
int n,m;
int cnt;

int main()
{
    cin >> n >> m;

    if(n==0)
        return 0;

    int left=n-1;
    int i=0;

    while(left)
    {
        ++cnt;
        if(cnt == m)
        {
            cout << i+1 << ' ';
            vis[i] = 1;
            --left;
            cnt=0;
        }

        i = (i+1)%n;
        while(vis[i])
        {
            i = (i+1)%n;
        }
    }

    cout << i+1;

}