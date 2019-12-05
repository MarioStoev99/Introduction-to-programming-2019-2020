#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
void pushElementArr(int arr[],int& len,int element)
{
    len++;
    for(int i = 0;i < len;i++)
    {
        if(arr[i] > element)
        {
            int temp = arr[i];
            arr[i] = element;
            element = temp;
        }
    }
}
void print(int arr[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[MAX_SIZE];
    int len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len < 1);
    for(int i = 0;i < len;i++)
    {
        cin >> arr[i];
    }
    pushElementArr(arr,len,15);
    print(arr,len);
    return 0;
}
