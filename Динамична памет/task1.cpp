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
void resize(int*& arr,size_t& size)
{
    int* new_arr = new(nothrow) int[size + 1];
    if(!new_arr)
    {
        cout << "error";
        return;
    }
    for(int i = 0;i < size;i++)
        new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
    size += 1;
}
void init(int* arr,size_t size)
{
    for(size_t i = 0;i < size;i++)
    {
        cin >> arr[i];
    }
}
void print(int* arr,size_t size)
{
    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
}
void pop(int*& arr,size_t& size)
{
    int* new_arr = new(nothrow) int[size - 1];
    if(!new_arr)
    {
        cout << "error";
        return;
    }
    for(int i = 0;i < size;i++)
        new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
    size -= 1;
}
void push(int*& arr,size_t& size,int element)
{
    resize(arr,size);
    arr[size - 1] = element;
}
int main()
{
    unsigned size;
    cin >> size;
    int* arr = nullptr;
    arr = create(size);
    if(!arr)
    {
        cout << "error";
        return 0;
    }
    init(arr,size);
    pop(arr,size);
    //push(arr,size,5);
    print(arr,size);
    _delete(arr);
    return 0;
}
