#include <iostream>
using namespace std;
const size_t MAX_SIZE = 129;
void _delete(int** matrix,size_t rows)
{
    for(size_t i = 0;i < rows;i++)
        delete[] matrix[i];
    delete[] matrix;
}
void init(int** matrix,int* arr,size_t rows)
{
    size_t k = 0;
    for(size_t i = 0;i < rows;i++)
    {
        unsigned size = arr[k];
        for(size_t j = 0;j < size;j++)
        {
            cin >> matrix[i][j];
        }
        k++;
    }
}
int** createMatrix(size_t rows,size_t cols)
{
    int** matrix = new(nothrow) int*[rows];
    if(!matrix)
        return matrix;
    for(int i = 0;i < rows;i++)
    {
        matrix[i] = new(nothrow) int[cols];
        if(!matrix[i])
        {
            _delete(matrix,rows);
            return nullptr;
        }
    }
    return matrix;
}
void print(int** matrix,int* arr,size_t rows)
{
    size_t k = 0;
    for(size_t i = 0;i < rows;i++)
    {
        size_t size = arr[k];
        for(size_t j = 0;j < size;j++)
        {
            cout << matrix[i][j] << " ";
        }
        k++;
        cout << endl;
    }
}
void sortRows(int**& matrix,size_t rows,int* arr,unsigned size)
{
    bool changed = false;
    unsigned sorted = 0;
    do
    {
        changed = false;
        for(unsigned i = rows - 1;i > sorted;i--)
        {
            if(arr[i] < arr[i - 1])
            {
                int* temp = matrix[i];
                matrix[i] = matrix[i - 1];
                matrix[i - 1] = temp;
                int temp1 = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp1;
                changed = true;
            }
        }
        sorted++;
    } while(changed);
}
int main()
{
    int arr[MAX_SIZE];
    size_t rows,cols;
    unsigned size = 0;
    cin >> rows;
    for(int i = 0;i < rows;i++)
    {
        cin >> arr[i];
    }
    int** matrix = nullptr;
    matrix = createMatrix(rows,cols);
    if(!matrix)
    {
        cout << "not memory enought";
        return 0;
    }
    init(matrix,arr,rows);
    sortRows(matrix,rows,arr,size);
    print(matrix,arr,rows);
    _delete(matrix,rows);
    return 0;
}
