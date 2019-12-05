#include <iostream>
#include <iomanip>
using namespace std;
const unsigned pi = 3.14;
int S(unsigned r)
{
    return pi*r*r;
}
int main()
{
    unsigned r;
    cout << "r = ";
    cin >> r;
    cout << S(r);
    return 0;
}
