#include <iostream>
using namespace std;

int isLargest(int number1,int number2)
{
    if(number1 > number2)
        return number1;
    return number2;
}
int main()
{
    int number1,number2;
    cin >> number1 >> number2;
    cout << isLargest(number1,number2);
    return 0;
}
