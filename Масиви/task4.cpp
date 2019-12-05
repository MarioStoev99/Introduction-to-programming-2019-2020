#include <iostream>
using namespace std;
const int SIZE = 1024;
bool isPrime(int num)
{
    if(num < 2)
        return false;
    if(num % 2 == 0)
        return num == 2;
    for(int i = 3;i*i <= num;i += 2)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}
void printPrimes(int arr[],int len)
{
    for(int i = 0;i < len;i++)
    {
        if(isPrime(arr[i]))
            cout << arr[i] << " ";
    }
}
int main()
{
    int arr[SIZE];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    printPrimes(arr,len);
    return 0;
}
