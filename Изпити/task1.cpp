#include <iostream>
using namespace std;
const size_t MAX_SIZE = 100;
char** createMatrix(int size)
{
	char** matrix = new(nothrow) char* [size];
	return matrix;
}
char* str(int size)
{
	char* str = new(nothrow) char[size];
	return str;
}
void deleteMatrix(char** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
int myStrcmp(const char* str, const char* str1)
{
	int i;
	for (i = 0; str[i] != '\0' && str[i] == str1[i]; i++)
		;
	return (int)(str[i] - str1[i]);
}
int myStrlen(char* str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}
void bubbleSort(char** matrix, int N)
{
	bool changed = false;
	int sorted = 0;
	do
	{
		changed = false;
		for (int i = N - 1; i > sorted; i--)
		{
			if (myStrcmp(matrix[i], matrix[i - 1]) < 0)
			{
				char* temp = matrix[i];
				matrix[i] = matrix[i - 1];
				matrix[i - 1] = temp;
				changed = true;
			}
		}
		sorted++;
	} while (changed);
}
void myStrcpy(char* str, const char* str1)
{
	int i;
	for (i = 0; str1[i] != '\0'; i++)
		str[i] = str1[i];
	str[i] = '\0';
}
bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}
bool isValid(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isLetter(str[i]))
			return false;
	}
	return true;
}
void init(char** matrix, char* str,int N)
{
	for (int i = 0; i < N; i++)
	{
		do
		{
			cin.getline(str, MAX_SIZE);
		} while (!isValid(str));
		int len = myStrlen(str);
		matrix[i] = new(nothrow) char[len + 1];
		if (!matrix[i])
		{
			deleteMatrix(matrix, i);
			matrix = nullptr;
			return;
		}
		myStrcpy(matrix[i], str);
	}
}
void print(char** matrix, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << matrix[i] << endl;
	}
}
void initSymbols(char matrix[][MAX_SIZE], unsigned K)
{
	for (unsigned i = 0; i < K; i++)
	{
		for (unsigned j = 0; j < K; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
int main()
{
	char symbols[MAX_SIZE][MAX_SIZE];
	char** matrix = nullptr;
	char str[MAX_SIZE];
	int N;
	cin >> N;
	cin.get();
	matrix = createMatrix(N);
	init(matrix, str, N);
	if (!matrix)
	{
		cout << "not memory enought";
		return  0;
	}
	bubbleSort(matrix, N);
	unsigned K;
	do
	{
		cin >> K;
	} while (K < 2 || K > 5);
	initSymbols(symbols, K);
	//print(matrix, N);
	deleteMatrix(matrix, N);
	return 0;
}
