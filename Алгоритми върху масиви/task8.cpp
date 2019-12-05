#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void bubbleSort(int arr[],int len)
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
}
void print(int arr[],int arr1[],int len)
{
    for(int i = 0;i < len;i++)
        cout << "M " << arr[i] << "; " << " L " << arr1[i] << endl;
}
int main()
{
    srand(time(0));
    int mans[10],womans[10];
    int len = 10;
    for(int i = 0;i < len;i++)
    {
        int temp = 0;
        do
        {
            temp = rand() % 200;
        } while(temp > 200 || temp < 150);
        mans[i] = temp;
    }
    for(int i = 0;i < len;i++)
    {
        int temp = 0;
        do
        {
            temp = rand() % 200;
        } while(temp > 200 || temp < 150);
        womans[i] = temp;
    }
    bubbleSort(mans,len);
    bubbleSort(womans,len);
    print(mans,womans,len);
    return 0;
}
