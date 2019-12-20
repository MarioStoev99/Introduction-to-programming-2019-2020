#include <iostream>
using namespace std;
const size_t MAX_SIZE = 129;
int myStrlen(const char* str)
{
    int count = 0;
    for(size_t i = 0;str[i] != 0;i++)
    {
        count++;
    }
    return count;
}
void reverse(char str[],int len)
{
    for(int i = 0;i < len / 2;i++)
    {
        char c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
    }
}
void print(const char* str)
{
    for(size_t i = 0;str[i] != 0;i++)
         cout << str[i];
}
int main()
{
    char str[MAX_SIZE];
    cin.getline(str,MAX_SIZE);
    int len = myStrlen(str);
    reverse(str,len);
    print(str);
    return 0;
}
