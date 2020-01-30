#include <iostream>
using namespace std;
const size_t MAX_SIZE = 1024;
void initMatrix(float matrix[][2], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void initMatrix1(float matrix[][2], float* arr, int M)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> matrix[i][j];
		}
		cin >> arr[i];
	}
}
bool isValid(float matrix[][2], float matrix1[][2], float* arr, int N, int M)
{
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		float x = matrix[i][j];
		float y = matrix[i][j + 1];
		bool flag = false;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				float x1 = matrix1[j][k];
				float y1 = matrix1[j][k + 1];
				float distance = (x - x1) * (x - x1) + (y - y1) * (y - y1);
				float radius = arr[j];
				if (distance <= radius * radius)
				{
					flag = true;
					break;
				}
			}
		}
		if (!flag)
			return false;
	}
	return true;
}
int main()
{
	static float matrix[MAX_SIZE][2];
	static float matrix1[MAX_SIZE][2];
	static float radius[MAX_SIZE];
	int N, M;
	cin >> N;
	cin >> M;
	initMatrix(matrix, N);
	initMatrix1(matrix1,radius, M);
	cout << isValid(matrix, matrix1,radius, N, M);
	return 0;
}
