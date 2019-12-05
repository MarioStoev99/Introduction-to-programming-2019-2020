#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
void print(int matrix[][MAX_SIZE],unsigned len)
{
    for(int i = 0;i < len;i++)
    {
        for(int j = 0;j < len;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void TransposeMatrix(int transposeMatrix[MAX_SIZE][MAX_SIZE],int matrix[][MAX_SIZE],unsigned len)
{
    for(int i = 0;i < len;i++)
    {
        for(int j = 0;j < len;j++)
        {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }
    for(int i = 0;i < len;i++)
    {
        for(int j = 0;j < len;j++)
        {
            matrix[i][j] = transposeMatrix[i][j];
        }
    }
}
void bubbleSort(int arr[],unsigned len)
{
    bool flag = false;
    unsigned count = 0;
    do
    {
        flag = false;
        for(int i = len - 1;i > count;i--)
        {
            if(arr[i] < arr[i - 1])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                flag = true;
            }
        }
        count++;
    } while(flag);
}
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposeMatrix[MAX_SIZE][MAX_SIZE];
    unsigned len;
    do
    {
        cin >> len;
    } while(len > MAX_SIZE || len == 0);
    for(int i = 0;i < len;i++)
        for(int j = 0;j < len;j++)
            cin >> matrix[i][j];
    for(int i = 0;i < len;i++)
    {
        bubbleSort(matrix[i],len);
    }
    print(matrix,len);
    TransposeMatrix(transposeMatrix,matrix,len);
    for(int i = 0;i < len;i++)
    {
        bubbleSort(matrix[i],len);
    }
    TransposeMatrix(transposeMatrix,matrix,len);
    print(matrix,len);
    return 0;
}
