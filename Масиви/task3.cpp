#include <iostream>
using namespace std;
const int SIZE = 1024;
void print(int arr[],int len)
{
    int min = arr[0];
    int max = arr[0];
    int indexMin = 0;
    int indexMax = 0;
    for(int i = 1;i < len;i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
            indexMin = i;
        }
        if(max < arr[i])
        {
            max = arr[i];
            indexMax = i;
        }
    }
    cout << indexMin << " : "<< min << endl;
    cout << indexMax << " : "<< max << endl;
}
int main()
{
    int arr[SIZE];
    int len;
    cout << "len = ";
    cin >> len;
    for(int i = 0;i < len;i++)
    {
        cin >> arr[i];
    }
    print(arr,len);
    return 0;
}
