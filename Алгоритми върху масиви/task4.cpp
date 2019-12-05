#include <iostream>
using namespace std;
const size_t MAX_SIZE = 100;
bool isSymetrical(int arr[],int len)
{
    for(int i = 0;i < len / 2;i++)
    {
        if(arr[i] != arr[len - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    int arr[MAX_SIZE];
    unsigned len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len < 1);
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    cout << isSymetrical(arr,len);
    return 0;
}
