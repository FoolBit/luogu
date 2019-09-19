#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 100003

struct LISNode
{
    int h,pos;
    LISNode(){};
    LISNode(int h_, int pos_):h(h_),pos(pos_){};

    bool operator < (const LISNode& a) const
    {
       if( h == a.h )
       {
           return pos < a.pos;
       }
       return h > a.h;
    }
}n1[MAX];

struct LDSNode
{
    int h,pos;
    LDSNode(){};
    LDSNode(int h_, int pos_):h(h_),pos(pos_){};

    bool operator < (const LDSNode& a) const
    {
       if( h == a.h )
       {
           return pos > a.pos;
       }
       return h < a.h;
    }
}n2[MAX];

int N;
int C[MAX];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos, int v)
{
    while(pos <= N)
    {
        C[pos] = max(v, C[pos]);
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int v = 0;
    while(pos > 0)
    {
        v = max(v, C[pos]);
        pos -= lowbit(pos);
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    N = 0;
    int h;
    while(cin >> h)
    {
        ++N;
        n1[N] = LISNode(h, N);
        n2[N] = LDSNode(h, N);
    }

    sort(n1+1, n1+N+1);
    sort(n2+1, n2+N+1);

    for(int i=1; i<=N; ++i)
    {
        int p = n1[i].pos;
        int v = query(p);
        update(p, v+1);
    }
    cout << query(N) << endl;

    memset(C, 0, sizeof(C));
    for(int i=1; i<=N; ++i)
    {
        int p = n2[i].pos;
        int v = query(p);
        update(p, v+1);
    }
    cout << query(N) << endl;

}

