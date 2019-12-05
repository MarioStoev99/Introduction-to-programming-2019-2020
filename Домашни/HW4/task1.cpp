#include <iostream>
using namespace std;
// проверка дали е просто,преди обхождах всички числа от 2 до n,но този алгоритъм
// е по-добър
bool isPrime(int num)
{
	if (num < 2)
		return false;
	if (num % 2 == 0)
		return num == 2;
	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void printPairs(int N)
{
	// проверка за четно
	if (N % 2 == 0)
	{
		// понеже се иска комутативност ще събирам числата от едната половина с тези от другата
		// по този начин избягвам двойки като (3,5) и (5,3).Започваме от 2
		//защото 1 не е просто
		for (int i = 2; i <= N / 2; i++)
		{
			for (int j = N / 2; j < N; j++)
			{
				// ако и двете са прайм + техният сбор прави N,то това е нашата двойка 
				if (isPrime(i) && isPrime(j) && i + j == N)
				{
					cout << "(" << i << "," << j << ")";
				}
			}
		}
	}
	// в противен случай нечетно
	else
		cout << "Are you joking with me, Euler? This number is not even!";
}
int main()
{
	// положително
	unsigned N;
	do
	{
		cin >> N;
	} while (N == 0);
	// викаме функцията print
	printPairs(N);
	return 0;
}
