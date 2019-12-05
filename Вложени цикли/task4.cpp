#include <iostream>
using namespace std;

int main()
{
    for(int i = 100;i < 1000;i++)
    {
        if((i % 10 != i / 10 % 10) && (i % 10 != i / 100) && (i / 10 % 10 != i / 100))
            cout << i << " ";
    }
    return 0;
}
