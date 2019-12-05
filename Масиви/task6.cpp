#include <iostream>
using namespace std;
const int SIZE = 1024;
int sum(int arr[],int len)
{
    int P = 1; //   четни
    int S = 0;  // нечетни
    for(int i = 0;i < len;i++)
    {
        if(i % 2 == 0)
            P *= arr[i];
        else
            S += arr[i];
    }
    return P-S;
}
int main()
{
    int arr[SIZE];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    cout << sum(arr,len);
    return 0;
}
