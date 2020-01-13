#include <iostream>
using namespace std;
bool isPrime(int number,int i)
{
    if(number < 2)
        return false;
    if(number == i)
        return true;
    if(number % i == 0)
        return false;
    isPrime(number,i + 1);
}
int main()
{
    int number;
    cin >> number;
    cout << isPrime(number,2);
    return 0;
}
