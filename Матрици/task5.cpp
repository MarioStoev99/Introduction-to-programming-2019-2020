#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const size_t MAX_SIZE = 100;
void print(int matrix[][MAX_SIZE],int rows,int cols)
{
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            if(j == 0 || i == 0 || i == rows - 1 || j == cols - 1)
                cout << setw(2) << matrix[i][j] << " ";
            else
                cout << setw(2) << "  ";
        }
        cout << endl;
    }
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
            matrix[i][j] = rand() % 100;
        }
    }
    print(matrix,rows,cols);
    return 0;
}
