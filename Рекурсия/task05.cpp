#include <iostream>
using namespace std;
void print(int number)
{
    if(number == 0)
        return;
    print(number / 10);
    cout << number % 10 << " ";
}
int main()
{
    int number;
    cin >> number;
    print(number);
    return 0;
}
