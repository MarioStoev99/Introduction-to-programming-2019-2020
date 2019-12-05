#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const size_t MAX_SIZE = 100;
void print(int matrix[][MAX_SIZE],size_t rows,size_t cols)
{
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void f(int matrix[][MAX_SIZE],int matrix1[][MAX_SIZE],int rows,int cols)
{
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            matrix[i][j] += matrix1[i][j];
        }
    }
}
int main()
{
    srand(time(0));
    int h;
    int matrix[MAX_SIZE][MAX_SIZE];
    int matrix1[MAX_SIZE][MAX_SIZE];
    size_t rows,cols;
    cin >> rows >> cols;
    if(rows > MAX_SIZE || cols > MAX_SIZE)
    {
        cout << "invalid input";
        return 0;
    }
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            matrix1[i][j] = rand() % 100;
        }
    }
    print(matrix,rows,cols);
    print(matrix1,rows,cols);
    f(matrix,matrix1,rows,cols);
    print(matrix,rows,cols);
    return 0;
}
