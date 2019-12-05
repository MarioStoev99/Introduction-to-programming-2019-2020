#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const size_t MAX_SIZE = 100;
void print(int matrix[][MAX_SIZE],size_t len)
{
    for(size_t i = 0;i < len;i++)
    {
        for(size_t j = 0;j < len;j++)
        {
            if(i == j || j == len - 1 - i)
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
    size_t len;
    cin >> len;
    if(len > MAX_SIZE)
    {
        cout << "invalid input";
        return 0;
    }
    for(size_t i = 0;i < len;i++)
    {
        for(size_t j = 0;j < len;j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
    print(matrix,len);
    return 0;
}
