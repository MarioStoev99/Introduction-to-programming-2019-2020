#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
void print(int arr[],unsigned len)
{
    for(int i = 0;i < len;i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[],int array[],unsigned len,unsigned& size)
{
    bool flag = false;
    unsigned count = 0;
    do
    {
        flag = false;
        for(int i = len - 1;i > count;i--)
        {
            if(arr[i] < arr[i - 1])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                flag = true;
            }
        }
        count++;
    } while(flag);
    for(int i = 0;i < len;i++)
    {
        if(arr[i] % 2 == 0)
        {
            array[size++] = arr[i];
        }
    }
}
int main()
{
    int arr[MAX_SIZE];
    int array[MAX_SIZE];
    unsigned size = 0;
    unsigned len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len == 0);
    for(int i = 0;i < len;i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr,array,len,size);
    print(array,size);
    return 0;
}
