#include <iostream>
using namespace std;
const int SIZE = 1024;
int multi(int arr[],int len)
{
    int sum = 1;
    for(int i = 0;i < len;i++)
    {
        sum *= arr[i];
    }
    return sum;
}
int sum(int arr[],int len)
{
    int mySum = 0;
    for(int i = 0;i < len;i++)
    {
        mySum += arr[i];
    }
    return mySum;
}
int main()
{
    int arr[SIZE];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    cout << multi(arr,len) << endl;
    cout << sum(arr,len);
    return 0;
}
