#include <iostream>
using namespace std;
int myAtoi(const char* str)
{
    int number = 0;
    for(size_t i = 0;str[i] != 0;i++)
    {
        char c = str[i];
        number = number*10 + c - '0';
    }
    return number;
}
int main()
{
    const char* str = "123";
    int res = myAtoi(str);
    cout << res;
    return 0;
}
