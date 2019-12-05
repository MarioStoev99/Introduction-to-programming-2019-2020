#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int sum = 0;
    for(int i = 0 ;i < n;i++)
    {
        cin >> n;
        sum += n;
    }
    cout << sum / n;
    return 0;
}
