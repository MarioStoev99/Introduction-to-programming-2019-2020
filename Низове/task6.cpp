#include <iostream>
using namespace std;
int myStrlen(const char* str)
{
    int count = 0;
    for(int i = 0;str[i] != 0;i++)
        count++;
    return count;
}
bool isPalindrome(const char* str,size_t len)
{
    for(size_t i = 0;str[i] != 0;i++)
    {
        if(str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    const char* str = "abcdba";
    size_t len = myStrlen(str);
    cout << isPalindrome(str,len);
    return 0;
}
