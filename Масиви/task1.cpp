#include <iostream>
using namespace std;

const int size = 1024;
int main()
{
    int arr[size];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 1;i <= len;i++)
        arr[i] = i;
    for(int i = 1;i <= len;i++)
    cout << arr[i] << " ";
    return 0;
}
