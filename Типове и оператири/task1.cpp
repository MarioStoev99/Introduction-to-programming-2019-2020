
#include <iostream>
using namespace std;

int main()
{
    int x = 827;
    cout << x % 10;
    x /= 10;
    cout << x % 10;
    x /= 10;
    cout << x % 10;
    return 0;
}
