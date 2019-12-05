#include <iostream>
using namespace std;

int main()
{
    int x,y;
    unsigned int R = 2;
    cin >> x >> y;
    if(x*x + y*y <= R*R && y >= 0)
        cout << "vutre sme";
    else if(x >= -1 && x <= 1 && y >= -4 && y <= 0)
        cout << "vutre sme";
    else
        cout << "ne sme vutre";
    return 0;
}
