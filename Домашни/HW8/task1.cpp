#include <iostream>
using namespace std;
// 4)връщаме ресурсите
void _delete(int** matrix, size_t N)
{
	for (size_t i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;
}
int** create(size_t N, size_t M)
{
	// 1)Поискване
	int** matrix = new(nothrow) int* [N];
	// 2)Проверка 
	if (!matrix)
		return matrix;
	for (size_t i = 0; i < N; i++)
	{
		// пак поискване
		matrix[i] = new(nothrow) int[M];
		// пак проверка
		if (!matrix[i])
		{
			// Ако случайно за някой от редовете не се е заделило масивче,трябва
			// да върнем ресурсите,които сме взели
			_delete(matrix, N);
			return nullptr;
		}
	}
	// връщаме указател към масив,чиито елементи са указатели към масиви
	return matrix;
}
// слагаме стойности в матрицата
void init(int** matrix, size_t N, size_t M)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
// принт функция
void print(int** matrix, size_t N, size_t M)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
// взимаме сумата на масив
int totalSumofRow(int* arr,size_t M)
{
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		sum += arr[i];
	}
	return sum;
}
// 3) Ползване
void sortRows(int** matrix, size_t N, size_t M)
{
	unsigned sorted = 0;
	bool changed = false;
	do
	{
		changed = false;
		for (size_t i = N - 1; i > sorted; i--)
		{
			// сравнявам сумите
			int sum1 = totalSumofRow(matrix[i],M);
			int sum2 = totalSumofRow(matrix[i - 1], M);
			if (sum1 < sum2)
			{
				// единственото различно с предишните сортировки е ,че разменям 
				// поинтъри,а не елементи
				int* temp = matrix[i];
				matrix[i] = matrix[i - 1];
				matrix[i - 1] = temp;
				changed = true;
			}
		}
	} while (changed);
}
int main()
{
	// ограничения
	unsigned N, M;
	do
	{
		cin >> N;
	} while (N == 0);
	do
	{
		cin >> M;
	} while (M == 0);
	//слагаме я да сочи в нищото
	int** matrix = nullptr;
	// създаваме я
	matrix = create(N, M);
	// проверка дали е създадена
	if (!matrix)
	{
		cout << "Not memory enought";
		return 0;
	}
	//слагаме стойности в матрицата
	init(matrix, N, M);
	// сортираме
	sortRows(matrix, N, M);
	// принтим
	print(matrix, N, M);
	// паметта не е безкрайна,затова връщаме ресурса
	_delete(matrix, N);
	return 0;
}
