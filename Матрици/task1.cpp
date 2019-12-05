#include <iostream>
using namespace std;
const unsigned MAX_SIZE = 100;
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
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int m,n;
    cin >> m >> n;
    if(n > MAX_SIZE || m > MAX_SIZE)
    {
        cout << "invalid input";
        return 0;
    }
    for(size_t i = 0;i < m;i++)
    {
        for(size_t j = 0;j < n;j++)
        {
            cin >> matrix[i][j];
        }
    }
   // print(matrix,m,n);
    return 0;
}
