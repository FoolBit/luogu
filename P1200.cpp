#include <iostream>
#include <string>

using namespace std;

int value(string str)
{
    int cnt = 1;
    int len = str.length();
    for(int i=0; i<len; ++i)
        cnt *= (str[i]-'@');
    return cnt % 47;
}

int main()
{
    string star, team;
    cin >> star >> team;

    if(value(star) == value(team))
        cout << "GO";
    else
        cout << "STAY";

}

