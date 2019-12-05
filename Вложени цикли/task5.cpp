#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "n = ";
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int count = i;
        int number = 1;
        while(count)
        {
            number *= i;
            count--;
        }
        sum += number;
    }
    cout << "sum : " << sum;
    return 0;
}
