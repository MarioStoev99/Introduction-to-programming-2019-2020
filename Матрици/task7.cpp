#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
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
}
int result(int matrix[][MAX_SIZE],int rows,int cols)
{
    int sum = 0;
    int countofOdd = 0;
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            if(j > i)
            {
                sum += matrix[i][j];
            }
            if(j < i)
            {
                if(matrix[i][j] % 2 != 0)
                    countofOdd++;
            }
        }
        cout << endl;
    }
    return countofOdd*sum;
}
int main()
{
    srand(time(0));
    int matrix[MAX_SIZE][MAX_SIZE];
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
            matrix[i][j] = rand() % 10;
        }
    }
    print(matrix,rows,cols);
    cout << result(matrix,rows,cols);
    return 0;
}
