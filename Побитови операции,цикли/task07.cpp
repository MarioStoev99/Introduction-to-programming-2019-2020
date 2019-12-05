
#include <iostream>
using namespace std;

int main()
{
    int n;
    int max = 0;
    int count = 0;
    while(true)
    {
        cin >> n;
        if(max > n)
        {
            cout << count;
            break;
        }
        else
        {
            count++;
            max = n;
        }
    }
    return 0;
}
