#include <iostream>
using namespace std;
const size_t MAX_SIZE = 129;
void toUpper(char str[])
{
   int differrence = 'a' - 'A';
   for(int i = 0;str[i] != 0;i++)
   {
       char c = str[i];
       if(c >= 'a' && c <= 'z')
       {
           str[i] -=  differrence;
       }
   }
}
void toLower(char str[])
{
    int difference = 'a' - 'A';
    for(int i = 0;str[i] != 0;i++)
    {
        char c = str[i];
        if(c >= 'A' && c <= 'Z')
        {

            str[i] += difference;
        }
    }
}
void print(char str[])
{
    for(int i = 0;str[i] != 0;i++)
        cout << str[i];
}
int main()
{
    char str[MAX_SIZE];
    cin.getline(str,MAX_SIZE);
    //toUpper(str);
    toLower(str);
    print(str);
    return 0;
}
