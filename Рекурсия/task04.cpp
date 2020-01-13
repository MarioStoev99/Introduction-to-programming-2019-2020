#include <iostream>
using namespace std;
void print(int number,int i,int countof0,int countof1)
{
    if(i == -1)
    {
        cout << "In number: "<< number << " we have " << countof0 <<
          " zeroes and " << countof1 << " ones!";
          return;
    }
    if(((number >> i) & 1) == 1)
        print(number,i - 1,countof0,countof1 + 1);
    else
        print(number,i - 1,countof0 + 1,countof1);
}
int main()
{
    int number;
    cin >> number;
    print(number,31,0,0);
    return 0;
}
