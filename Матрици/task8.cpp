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
void findSedl(int matrix[][MAX_SIZE],size_t rows,size_t cols)
{
    int countofPoints = 0;
    for(size_t i = 0;i < rows;i++)
    {
        int max = matrix[i][0];
        size_t current_j = 0;
        for(size_t j = 0;j < cols;j++)
        {
            if(max < matrix[i][j])
            {
                max = matrix[i][j];
                current_j = j;
            }
        }
        bool isMin = true;
        for(int k = 0;k < cols;k++)
        {
            if(max > matrix[k][current_j])
            {
                isMin = false;
            }
        }
        if(isMin)
        {
            cout << "(" << i << " , " << current_j << ") ------> " << matrix[i][current_j] << endl;
            countofPoints++;
        }
    }
    if(countofPoints == 0)
        cout << "Sorry,nqma takava tochka";
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
    /*
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    */
    for(size_t i = 0;i < rows;i++)
    {
        for(size_t j = 0;j < cols;j++)
        {
            cin >> matrix[i][j];
        }
    }
    //print(matrix,rows,cols);
    findSedl(matrix,rows,cols);
    return 0;
}
