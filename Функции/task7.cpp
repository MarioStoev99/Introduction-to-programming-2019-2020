#include <iostream>
using namespace std;
int func(int x,int y,int count = 0)
{
    while(x % y == 0)
    {
        count++;
        x /= y;
    }
    return count;
}
int main()
{
    int x,y;
    cin >> x >> y;
    cout << func(x,y);
    return 0;
}
