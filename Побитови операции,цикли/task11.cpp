#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int n1 = n;
    while(n)
    {
        cout << n % 10 << " ";
        n /= 10;
    }
    return 0;
}
