#include <iostream>
using namespace std;
const size_t MAX_SIZE = 128;
void changeSymbol(char str[],char c1,char c2)
{
    for(size_t i = 0;str[i] != 0;i++)
    {
        if(str[i] == c1)
            str[i] = c2;
    }
}
void print(char str[])
{
    for(size_t i = 0;str[i] != 0;i++)
    {
        cout << str[i];
    }
}
int main()
{
    char str[MAX_SIZE];
    cin.getline(str,MAX_SIZE);
    char c1,c2;
    cin >> c1 >> c2;
    changeSymbol(str,c1,c2);
    print(str);
    return 0;
}
