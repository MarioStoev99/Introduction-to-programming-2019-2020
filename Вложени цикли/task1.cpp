#include <iostream>
using namespace std;

int main()
{
    unsigned a,b;
    int sum = 0;
    cin >> a >> b;
    for(int i = a;i <= b;i++)
    {
        bool isPrime = true;
        if(i < 2)
        {
            isPrime = false;
        }
        else
        {
            for(int j = 2;j < i;j++)
            {
                if(i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime)
            sum += i;
    }
    cout << "sum : " << sum;
    return 0;
}
