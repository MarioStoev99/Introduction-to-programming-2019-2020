#include <iostream>
using namespace std;
int myAbs(int number)
{
    if(number < 0)
        return -(number);
    return number;
}
int main()
{
    int number;
    cin >> number;
    cout << myAbs(number);
    return 0;
}
