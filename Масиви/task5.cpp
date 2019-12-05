#include <iostream>
using namespace std;
const int SIZE = 1024;
int print(int arr[],int len)
{
    int sum = 1;
    for(int i = 0;i < len;i++)
    {
        if(arr[i] % 2 != 0)
        {
            sum *= i;
        }
    }
    return sum;
}
int main()
{
    int arr[SIZE];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    cout << print(arr,len);
    return 0;
}
