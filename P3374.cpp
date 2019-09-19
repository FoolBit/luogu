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
    int sum[MAX];
    memset(sum, 0, sizeof(sum));

    for(int i=1; i<=N; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for(int i=1; i<=N; ++i)
    {
        C[i] = sum[i] - sum[i - lowbit(i)];
    }
}

int ask(int x, int y)
{
    return query(y) - query(x-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    init();

    int c,x,k;
    while(M--)
    {
        cin >> c >> x >> k;
        if(c == 1)
        {
            update(x, k);
        }
        else
        {
            cout << ask(x,k) << endl;
        }
    }
}
