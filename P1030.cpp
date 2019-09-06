#include <iostream>
#include <string>

using namespace std;

void getPre(string mids, string posts)
{
    char midPoint = *posts.rbegin();
    cout << midPoint;

    int midPos = mids.find(midPoint);
    int lenLeft = midPos;
    int lenRight = mids.length() - midPos - 1;

    if(lenLeft)
        getPre(mids.substr(0,lenLeft), posts.substr(0, lenLeft));

    if(lenRight)
        getPre(mids.substr(midPos+1, lenRight), posts.substr(lenLeft, lenRight));

}

int main()
{
    string mids, posts;
    cin >> mids >> posts;
    getPre(mids, posts);
}