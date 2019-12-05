#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int sum = 1;
    for(int i = n;i > 0;i--)
    {
        sum *= i;
    }
    cout << sum;
    return 0;
}
