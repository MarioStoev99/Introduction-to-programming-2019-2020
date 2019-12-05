#include <iostream>
using namespace std;

int main()
{
    unsigned number = 62;
    for(int i = 31;i >= 0;i--)
    {
        cout << ((number >> i) & 1);
    }
    return 0;
}
