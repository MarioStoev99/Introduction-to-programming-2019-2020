#include <iostream>
using namespace std;

int main()
{
    unsigned int A = 19006;
    for(int i = 15;i >= 0;i--)
    {
        cout << ((A >> i) ^ 1);
    }
    return 0;
}
