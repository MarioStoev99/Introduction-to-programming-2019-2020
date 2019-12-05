#include <iostream>
using namespace std;
int fibDigit(int number)
{
    if(number == 0) return 0;
    if(number == 1) return 1;
    int fib0 = 0;
    int fib1 = 1;
    for(int i = 0;i < number;i++)
    {
        int fib2 = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib2;
    }
    return fib0;
}
int main()
{
    int number;
    cin >> number;
    cout << fibDigit(number);
    return 0;
}
