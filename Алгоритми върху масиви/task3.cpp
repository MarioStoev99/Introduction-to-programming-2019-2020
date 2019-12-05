#include <iostream>
using namespace std;
const size_t MAX_SIZE = 100;
void eraseElement(int arr[],unsigned& len,int element)
{
    for(int i = 0;i < len;i++)
    {
        if(arr[i] == element)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    len--;
}
void print(int arr[],int len)
{
    for(int i = 0;i < len;i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[MAX_SIZE];
    unsigned len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len == 0);
    for(int i = 0;i < len;i++)
        cin >> arr[i];
    eraseElement(arr,len,7);
    print(arr,len);
    return 0;
}
