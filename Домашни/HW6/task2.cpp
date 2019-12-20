#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX_SIZE = 9;
// принт функция
void print(char matrix[][MAX_SIZE], int len)
{
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			// само ,ако имаме тези два символа принтим на конзолата
			if (matrix[i][j] == 'X' || matrix[i][j] == 'O')
			{
				cout << "[" << matrix[i][j] << "]";
			}
			// в противен случай интервалче
			else
				cout << "[ ]";
		}
		cout << endl;
	}

}
// тук ситуацията е аналогична като в контролното с магическия квадрат,самоче там 
// се искаше и 4те функции да върнат true.В тази ситуация ние сме удовлетворени 
// и на един път тру от общо 4
bool equalRow(char matrix[][MAX_SIZE], int len, char c)
{
	for (int i = 1; i <= len; i++)
	{
		// правя си брояч,който ще брои еднаквите символи
		int count = 0;
		for (int j = 1; j <= len; j++)
		{
			// ако символът съвпада с подадения като аргумент символ,тогава дигаме каунта
			if (matrix[i][j] == c)
				count++;
		}
		// и сега ,ако дължината е равна на каунта имаме един пълен ред от еднакви 
		// символи и съответно връщаме Да
		if (count == len)
			return true;
	}
	// ако стигнем до тук ,не сме намерили нищо все още
	return false;
}
// следим за колоните
bool equalCol(char matrix[][MAX_SIZE], int len, char c)
{
	// логиката е почти същата с разликата,че тук увеличаваме първо редовете,а после колоните
	for (int j = 1; j <= len; j++)
	{
		int count = 0;
		for (int i = 1; i <= len; i++)
		{
			if (matrix[i][j] == c)
				count++;
		}
		if (count == len)
			return true;
	}
	return false;
}
bool diag(char matrix[][MAX_SIZE], int len, char c)
{
	// извън фор,защото трябва да обходим цялата матрица
	int count = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			// стойностите на главния диагонал са тези,за които i == j
			if (i == j && matrix[i][j] == c)
				count++;
		}
	}
	// ако са равни връща тру,в противен случай фоулс
	return count == len;
}
bool secondDiag(char matrix[][MAX_SIZE], int len, char c)
{
	int count = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			// формула за вторичен диагонал
			if (j == len + 1 - i && matrix[i][j] == c)
				count++;
		}
	}
	return count == len;
}
// играч срещу играч
void PvP(char matrix[][MAX_SIZE], int len)
{
	// принтя началната матрица с празни поленца
	print(matrix, len);
	// числа от [1,N]
	unsigned x, y;
	// булева,която ще ми казва дали играч 1 е на ред
	bool player1 = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (player1)
			{
				// важно е дали в матрицата мястото на (х,у) вече не е заето
				do
				{
					cout << "It's Player 1's turn:" << endl;
					// също е важно дали се спазват ограниченията за х и у
					do
					{
						cin >> x;
					} while (x > len || x < 1);
					do
					{
						cin >> y;
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				// вече сме (х,у),такива че спазват ограниченията и в същото време
				// на тези координати нямаме елемент
				matrix[x][y] = 'X';
				// вече играч1 е сложил Х и е време за принтене
				print(matrix, len);
				// веднага след всеки ход идва проверка,ако поне едно от 4те условия
				// е изпълнено ,то тогава имаме победител
				if (equalRow(matrix, len, 'X') || equalCol(matrix, len, 'X') ||
					diag(matrix, len, 'X') || secondDiag(matrix, len, 'X'))
				{
					cout << "Player 1 won!" << endl;
					// програмата спира
					return;
				}
				// ако пък все още няма победител е на ход втория игра
				player1 = false;
			}
			// на ред е вторият играч
			else
			{
				// ограниченията са същите
				do
				{
					cout << "It's PLayer 2's turn:" << endl;
					do
					{
						cin >> x;
					} while (x > len || x < 1);
					do
					{
						cin >> y;
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				// слагаме символа О в матрицата
				matrix[x][y] = 'O';
				// принтим
				print(matrix, len);
				// отново проверка,ако сме намери len на брой О,в поне една функция
				// играта приключва
				if (equalRow(matrix, len, 'O') || equalCol(matrix, len, 'O') ||
					diag(matrix, len, 'O') || secondDiag(matrix, len, 'O'))
				{
					cout << "Player 2 won!" << endl;
					return;
				}
				// иначе играта продължава с ход на първия играч
				player1 = true;
			}
		}
	}
	// ако не сме намерили победител,имаме равенство
	cout << "Equal!" << endl;
}
// останалите 2 функции са същите
void PvC(char matrix[][MAX_SIZE], int len)
{
	print(matrix, len);
	unsigned x, y;
	bool player1 = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (player1)
			{
				do
				{
					cout << "It's Player 1's turn:" << endl;
					do
					{
						cin >> x;
					} while (x > len || x < 1);
					do
					{
						cin >> y;
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				matrix[x][y] = 'X';
				print(matrix, len);
				if (equalRow(matrix, len, 'X') || equalCol(matrix, len, 'X') ||
					diag(matrix, len, 'X') || secondDiag(matrix, len, 'X'))
				{
					cout << "Player 1 won!" << endl;
					return;
				}
				player1 = false;
			}
			else
			{
				cout << "It's PLayer 2's turn:" << endl;
				// единствената разлика идва тук с ранд функцията,която генерира
				// произволни (х,у)
				do
				{
					do
					{
						x = rand() % (len + 1);
					} while (x > len || x < 1);
					do
					{
						y = rand() % (len + 1);
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				matrix[x][y] = 'O';
				print(matrix, len);
				if (equalRow(matrix, len, 'O') || equalCol(matrix, len, 'O') ||
					diag(matrix, len, 'O') || secondDiag(matrix, len, 'O'))
				{
					cout << "Player 2 won!" << endl;
					return;
				}
				player1 = true;
			}
		}
	}
	cout << "Equal!" << endl;
}
// + бонус функцията,когато играят компютрите
void CvC(char matrix[][MAX_SIZE], int len)
{
	print(matrix, len);
	unsigned x, y;
	bool player1 = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (player1)
			{
				cout << "It's Player 1's turn:" << endl;
				do
				{
					do
					{
						x = rand() % (len + 1);
					} while (x > len || x < 1);
					do
					{
						y = rand() % (len + 1);
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				matrix[x][y] = 'X';
				print(matrix, len);
				if (equalRow(matrix, len, 'X') || equalCol(matrix, len, 'X') ||
					diag(matrix, len, 'X') || secondDiag(matrix, len, 'X'))
				{
					cout << "Player 1 won!" << endl;
					return;
				}
				player1 = false;
			}
			else
			{
				cout << "It's PLayer 2's turn:" << endl;
				do
				{
					do
					{
						x = rand() % (len + 1);
					} while (x > len || x < 1);
					do
					{
						y = rand() % (len + 1);
					} while (y > len || y < 1);
				} while (matrix[x][y] == 'X' || matrix[x][y] == 'O');
				matrix[x][y] = 'O';
				print(matrix, len);
				if (equalRow(matrix, len, 'O') || equalCol(matrix, len, 'O') ||
					diag(matrix, len, 'O') || secondDiag(matrix, len, 'O'))
				{
					cout << "Player 2 won!" << endl;
					return;
				}
				player1 = true;
			}
		}
	}
	cout << "Equal!" << endl;
}
int main()
{
	srand(time(0));
	// декларация
	char matrix[MAX_SIZE][MAX_SIZE];
	unsigned len;
	unsigned gameMode;
	// ограничения и дефиниране на променливите
	do
	{
		cout << "Choose game mode(1-PvP,2-PvC,3-CvC):" << endl;
		cin >> gameMode;
	// допускат се само числа 1,2 и 3
	} while (gameMode > 3 || gameMode < 1);
	do
	{
		cout << "enter grid size:" << endl;
		cin >> len;
	// допускат се числа само от 3 до 9 включително
	} while (len < 3 || len > MAX_SIZE);
	// посредством gameMode променливата продължаваме в 1 от трите случая
	if (gameMode == 1)
		PvP(matrix, len);
	else if (gameMode == 2)
		PvC(matrix, len);
	else
		CvC(matrix, len);
	system("pause");
	// може ли мнение
	return 0;
}
