#include <iostream>
using namespace std;
void print(int number,int i)
{
    if(i == -1)
        return;
    cout << ((number >> i) & 1);
    print(number,i - 1);
}
int main()
{
    int number;
    cin >> number;
    print(number,31);
    return 0;
}
