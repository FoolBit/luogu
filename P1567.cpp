#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int max_temp = 0;
    int cnt = 1;
    int last,now;
    cin >> last;
    for(int i=1; i<N; ++i)
    {
        cin >> now;
        cnt = last < now? (cnt+1):1;
        max_temp = max_temp > cnt?max_temp:cnt;
        last = now;
    }
    cout << max_temp;
}