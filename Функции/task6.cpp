#include <iostream>
using namespace std;
bool isPrime(int number)
{
    if(number < 2)
        return false;
    if(number % 2 == 0)
        return number == 2;
    for(int i = 3;i*i < number;i += 2)
    {
        if(number % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int number;
    cin >> number;
    cout << isPrime(number);
    return 0;
}
