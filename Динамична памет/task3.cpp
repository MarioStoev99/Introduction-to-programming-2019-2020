#include <iostream>
using namespace std;
int* create(size_t size)
{
    int* arr = new(nothrow) int[size];
    return arr;
}
void _delete(int* arr)
{
    delete[] arr;
}
void init(int* arr,size_t size)
{
    for(int i = 0;i < size;i++)
        cin >> arr[i];
}
void print(int* arr,size_t size)
{
    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
}
bool isPrime(int num)
{
    if(num < 2)
        return false;
    if(num % 2 == 0)
        return num == 2;
    for(int i = 3;i*i <= num;i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}
int main()
{
    size_t size;
    cin >> size;
    int* arr = nullptr;
    arr = create(size);
    if(!arr)
    {
        cout << "error";
        return 0;
    }
    init(arr,size);
    for(int i = 0;i < size;i++)
    {
        if(isPrime(arr[i]))
            cout << arr[i] << " ";
    }
    _delete(arr);
    return 0;
}
