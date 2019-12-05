#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cin >> x >> y;
    char c;
    cin >> c;
    if(c == '&')
    {
        if(x == 1 && y == 1)
            cout << 1;
        else
            cout << 0;
    }
    if(c == '|')
    {

        if(x == 1 || y == 1)
            cout << 1;
        else
            cout << 0;
    }
    if(c == '^')
    {
        if(x == y)
            cout << 0;
        else
            cout << 1;
    }
    return 0;
}
