#include <iostream>
using namespace std;
void _delete(int** matrix,size_t rows)
{
    for(size_t i = 0;i < rows;i++)
    {
        if(matrix[i] != nullptr)
        {
            delete[] matrix[i];
        }
    }
    delete[] matrix;
}
int** createMatrix(size_t rows,size_t cols)
{
    int** matrix = new(nothrow) int*[rows];
    if(!matrix)
    {
        return matrix;
    }
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
void init(int** matrix,size_t rows,size_t cols)
{
    for(int i = 0;i < rows;i++)
        for(int j = 0;j < cols;j++)
            cin >> matrix[i][j];
}
void print(int** matrix,size_t rows,size_t cols)
{
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void eraseRows(int** matrix,size_t rows,size_t cols)
{
    for(int i = 0;i < rows;i++)
    {
        int sum = 0;
        for(int j = 0;j < cols;j++)
        {
            sum += matrix[i][j];
        }
        if(sum % 2 != 0)
        {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
    }
}
int main()
{
    size_t rows,cols;
    cin >> rows >> cols;
    int** matrix = nullptr;
    matrix = createMatrix(rows,cols);
    if(!matrix)
    {
        cout << "error";
        return 0;
    }
    init(matrix,rows,cols);
    eraseRows(matrix,rows,cols);
    print(matrix,rows,cols);
    _delete(matrix,rows);
    return 0;
}
