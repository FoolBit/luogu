#include <iostream>

using namespace std;

int n;
int MAX;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    MAX = n>>1;

    int cnt=3;
    for(int i=1,j=2;i<=MAX;)
    {
        if(cnt < n)
        {
            ++j;
            cnt+=j;
        }
        else if(cnt > n)
        {
            cnt-=i;
            ++i;
        }
        else
        {
            cout << i << ' ' << j << endl;
            cnt-=i;
            ++i;
        }
    }
}
