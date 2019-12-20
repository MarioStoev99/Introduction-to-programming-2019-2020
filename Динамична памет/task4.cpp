#include <iostream>
using namespace std;
int* create(size_t size)
{
    int* arr = new(nothrow) int[size];
    return arr;
}
void init(int* arr,size_t size)
{
    for(int i = 0;i < size;i++)
        cin >> arr[i];
}
void print(const int* arr,size_t size)
{
    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
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
void insert(int*& arr,size_t size,size_t pos,int element)
{
    for(int i = pos;i < size;i++)
    {
        int temp = arr[i];
        arr[i] = element;
        element = temp;
    }
}
void confluence(int*& arr,const int* _arr,size_t& size,size_t _size)
{
    size_t index = 0;
    size_t _index = 0;
    unsigned len = size + _size;
    while(size != index && _size != _index)
    {
        if(arr[index] > _arr[_index])
        {
            resize(arr,size);
            insert(arr,size,index,_arr[_index]);
            _index++;
            index++;
        }
        else
            index++;
    }
    resize(arr,size);
    arr[index] = _arr[_index];
}
int main()
{
    size_t size,_size;
    cin >> size;
    int* arr = nullptr;
    arr = create(size);
    init(arr,size);
    int* _arr = nullptr;
    cin >> _size;
    _arr = create(_size);
    init(_arr,_size);
    confluence(arr,_arr,size,_size);
    print(arr,size);
    _delete(arr);
    _delete(_arr);
    return 0;
}
