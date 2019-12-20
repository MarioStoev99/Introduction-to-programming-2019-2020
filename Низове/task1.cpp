#include <iostream>
using namespace std;
bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int main()
{
    char str;
    cin >> str;
    cout << isAlpha(str);
    return 0;
}
