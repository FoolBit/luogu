#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500002
int a[MAX];
int C[MAX];
int N,M;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos,int delta)
{
    while(pos <= N)
    {
        C[pos] += delta;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += C[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

void init()
{
    for(int i=1; i<=N; ++i)
    {
        cin >> a[i];
    }
}

int ask(int x)
{
    return a[x] + query(x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    init();

    int c,x,y,k;
    while(M--)
    {
        cin >> c;
        if(c == 1)
        {
            cin >> x >> y >> k;
            update(x, k);
            update(y+1, -k);
        }
        else
        {
            cin >> x;
            cout << ask(x) << endl;
        }
    }
}
