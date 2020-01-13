#include <iostream>
using namespace std;
void print(int number)
{
    if(number == 0)
        return;
    cout << number % 10 << " ";
    print(number / 10);
}
int main()
{
    int number;
    cin >> number;
    print(number);
    return 0;
}
