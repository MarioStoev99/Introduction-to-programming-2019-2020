#include <iostream>
using namespace std;
const size_t MAX_SIZE = 100;
bool isValid(int arr[],int len)
{
    for(int i = 0;i < len - 1;i++)
    {
        if(arr[i] < arr[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int arr[MAX_SIZE];
    int len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len < 0);
    for(int i = 0;i < len;i++)
    {
            cin >> arr[i];
    }
    cout << isValid(arr,len);
    return 0;
}
