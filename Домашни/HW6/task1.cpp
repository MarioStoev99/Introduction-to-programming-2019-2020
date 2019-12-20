#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const size_t MAX_SIZE = 100;
// принт функция
void print(int matrix[][MAX_SIZE], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void compareSums(int matrix[][MAX_SIZE], int N, int M,int sum,int row,int& count)
{
	// каунтът е по амперсанд,за да съхраня стойността за всички въртележки
	for (int i = 0; i < M; i++)
	{
		int sumofColum = 1;
		int j;
		for (j = 0; j < N; j++)
		{
			sumofColum *= matrix[j][i];
		}
		// вече съм намерил сумата на една колона и е време за проверка дали съвпада
		// с тази на реда
		if (sumofColum == sum)
		{
			// ако съм тук дигам двойките и печатам координатите на реда и колоната
			count++;
			cout << row << ", " << i << endl;
		}
	}
}
void printPairs(int matrix[][MAX_SIZE], int N, int M)
{
	// каунтър,който ще следи дали имаме двойки
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		// започваме с 1,защото единицата е неутралният елемент относно умножението
		int sum = 1;
		for (int j = 0; j < M; j++)
		{
			sum *= matrix[i][j];
		}
		// пращаме реда и го сравняваме с всяка колона
		compareSums(matrix, N, M,sum,i,count);
	}
	// ако не сме намерили двойки 
	if (count == 0)
		cout << "no match" << endl;
}
int main()
{
	// матрицата може да бъде изведена от конзолата,а също така и със случайни стойности
	srand(time(0));
	int matrix[MAX_SIZE][MAX_SIZE];
	int N, M;
	// ограничения
	do
	{
		cin >> N;
	} while (N > 100 || N <= 0);
	do
	{
		cin >> M;
	} while (M > 100 || M <= 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// първи вариант с ранд функцията
			//matrix[i][j] = rand() % MAX_SIZE;
			// втори от конзолата
			cin >> matrix[i][j];
		}
	}
	// ако случайно се използва ранд
	//print(matrix, N, M);
	// викаме функцията ,за да изпринтим двойките координати
	printPairs(matrix, N, M);
	return 0;
}
