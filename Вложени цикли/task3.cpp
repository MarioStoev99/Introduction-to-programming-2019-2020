#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "vuvedete chislo : ";
    cin >> number;
    int i = 2;
    while(number != 1)
    {
        if(number % i == 0)
        {
            cout << i << " ";
            number /= i;
        }
        else
            i++;
    }
    return 0;
}
