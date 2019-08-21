#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct People
{
    int id;
    int W;

    People(int id_,int W_):id(id_), W(W_){};

    bool operator < (const People & b)
    {
        if(W == b.W)
            return id < b.id;
        return W > b.W;
    }

};

int n,k;
int E[10];

int main()
{
    vector<People> peoples;

    cin >> n >> k;
    for(int i=0; i<10; ++i)
        cin >> E[i];

    int w;
    for(int i=0; i<n; ++i)
    {
        cin >> w;
        peoples.push_back(People(i, w));
    }

    sort(peoples.begin(), peoples.end());

    for(int i=0; i<n; ++i)
        peoples[i].W += E[i % 10];

    sort(peoples.begin(), peoples.end());

    cout << peoples[0].id + 1;
    for(int i=1; i<k; ++i)
        cout << ' ' << peoples[i].id + 1;

}