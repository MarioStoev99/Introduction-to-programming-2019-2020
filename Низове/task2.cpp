#include <iostream>
using namespace std;
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
int main()
{
    char c;
    cin >> c;
    cout << isDigit(c);
    return 0;
}
