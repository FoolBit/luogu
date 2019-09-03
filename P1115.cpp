#include <iostream>

using namespace std;

int MAX=-1000000;
int cnt;
int n;

int main()
{
    cin >> n;
    int a;

    while(n--)
    {
        cin >> a;
        MAX = max(MAX, a);

        cnt += a;
        MAX = max(MAX, cnt);
        if(cnt < 0)
            cnt = 0;
    }
    cout << MAX;
}