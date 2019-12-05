#include <iostream>
using namespace std;

int main()
{
    for(int i = 1;i <= 7;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    int n = 1;
    cout << endl;
    for(int i = 1;i <= 7;i++)
    {
        n = 1;
        for(int j = 1;j <= 7;j++)
        {
            if(i == j || j > i)
            {
                cout << n++ << " ";
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
    int p = 1;
    for(int i = 1;i <= 8;i++)
    {
        for(int j = 1;j <= 8;j++)
        {
            cout << p++ << " ";
            if(p == 4)
            {

            }
        }
    }
    return 0;
}
