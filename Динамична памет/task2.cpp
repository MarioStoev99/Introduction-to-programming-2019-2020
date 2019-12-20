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
    for(size_t i = 0;i < size;i++)
        cin >> arr[i];
}
void print(const int* arr,size_t size)
{
    for(size_t i = 0;i < size;i++)
        cout << arr[i] << " ";
}
void resize(int*& arr,size_t& size,int temp)
{
    int* new_arr = new(nothrow) int[size + temp];
    if(!arr)
    {
        cout << "error";
        return;
    }
    for(size_t i = 0;i < size;i++)
        new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
    size += temp;
}
void insert(int*& arr,size_t& size,unsigned pos,int number)
{
    resize(arr,size,1);
    for(int i = pos;i < size;i++)
    {
        int temp = arr[i];
        arr[i] = number;
        arr[size - 1] = temp;
    }
}
void remove(int*& arr,size_t& size,size_t index)
{
    for(int i = index;i < size - 1;i++)
    {
        arr[i] = arr[i + 1];
    }
    resize(arr,size, - 1);
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
    //insert(arr,size,4,123);
    remove(arr,size,1);
    print(arr,size);
    _delete(arr);
    return 0;
}
