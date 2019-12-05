#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "broi chisla : ";
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int number;
        cout << i << " : ";
        cin >> number;
        while(number)
        {
            int lastDigit = number % 10;
            sum += lastDigit;
            number /= 10;
        }
    }
    cout << "sum = " << sum;
    return 0;
}
