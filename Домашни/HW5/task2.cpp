#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Марио е на 35 години и не може да върви повече от 10000 стъпки
const int MAX_SIZE = 10000;
// функцийка,която ми намира простите числа
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
// отпечатване на поредицата
void print(int sequence[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << sequence[i] << " ";
	}
	cout << endl;
}
// 1)
void theLongestTraining(int sequence[], int len)
{
	// трябва да намеря стартовата позиция,защото може да започнем с 0-ли
	bool findstartingPos = false;
	// ще запаметявам стартовата позиция в тази променлива
	unsigned startingPos = 0;
	// крачкомера
	unsigned runLenght = 0;
	// ще броя нулите с този каунт
	unsigned countofZeroes = 0;
	for (int i = 0; i < len; i++)
	{
		// ако сме на 1-ца и вече сме намерили стартова позиция
		if (sequence[i] == 1 && !findstartingPos)
		{
			// запаметяваме я,дигаме крачкомера,намерили сме стартова и
			// повече няма да влезем в този иф
			startingPos = i;
			runLenght++;
			findstartingPos = true;
		}
		// ако сме на 1-ца
		else if (sequence[i] == 1)
		{
			// дигаме дължината и махаме нулите
			countofZeroes = 0;
			runLenght++;
		}
		// в противен случай сме на 0-ла
		else
		{
			// преди всичко гледаме дали сме намерили стартова позиция
			if (findstartingPos)
			{
				// ако сме намерили такава,дигаме нулите и крачкомера
				countofZeroes++;
				runLenght++;
				// и ако сме прескочили границата от 3те стъпки,то Марио губи 
				// живот и приключваме дейността
				if (countofZeroes > 3)
				{
					// разбира се, трябва да извадя 4-те нули,защото те не ми
					// участват в крачкомера
					runLenght -= countofZeroes;
					cout << "Best starting position is " << startingPos <<
						" and the run length is " << runLenght << " steps." << endl;
					// спира функцията
					return;
				}
			}
		}
	}
	// може цялото трасе да е ок,затова се подсигурявам за такъв случай
	cout << "Best starting position is " << startingPos <<
		" and the run length is " << runLenght << " steps." << endl;
}
// 2)
void theLongestSequence(int sequence[], int len)
{
	// временна максимална дължина и индекс
	unsigned lenghtofSequence = 0;
	unsigned startSequenceIndex = 0;
	// максималните параметри за цялото трасе
	unsigned maxSequence = 0;
	unsigned maxSequenceIndex = 0;
	// 0-ли не ни интересуват,пак се подсигурявам за стартова позиция
	bool findstartingPos = false;
	for (int i = 0; i < len; i++)
	{
		// аналогично на горното
		if (sequence[i] == 1 && !findstartingPos)
		{
			startSequenceIndex = i;
			lenghtofSequence++;
			findstartingPos = true;
			maxSequence = lenghtofSequence;
		}
		// ако сме на 1-ца
		else if (sequence[i] == 1)
		{
			// и ако случайно сме попаднали предната итерация на 0,трябва
			// отново да сложим стартова позиция
			if (lenghtofSequence == 0)
			{
				startSequenceIndex = i;
			}
			// дигаме дължината,защото сме на 1-ца
			lenghtofSequence++;
			// и ако новата дължина е по-голяма от максималната,то сме готови
			// да я запишем като максимална такава
			if (lenghtofSequence > maxSequence)
			{
				maxSequence = lenghtofSequence;
				maxSequenceIndex = startSequenceIndex;
			}
		}
		// в протичен случай нашата поредица се разваля
		else
		{
			lenghtofSequence = 0;
		}
	}
	// време за принтене на най-оптималното решение
	cout << "Longest platform starts from position " << maxSequenceIndex <<
		" and has lenght of " << maxSequence << " steps." << endl;
}
// 3)
void findPrimesSequence(int sequence[],int len)
{
	// ще правя масив,в който ще си пазя простите числа,започвам със сайз 0
	unsigned size = 0;
	// масивът,в който ще пазя числата
	int primeNumbers[MAX_SIZE];
	// дължина на всяка поредица от 1-ци
	unsigned lenghtofSequence = 0;
	for (int i = 0; i < len; i++)
	{
		// ако сме на 1 дигаме нашата поредица
		if (sequence[i] == 1)
			lenghtofSequence++;
		// в противен случай гледаме дали тази поредица е просто число
		else
		{
			if (isPrime(lenghtofSequence))
			{
				// ако сме тук,записваме числото и дигаме дължината
				primeNumbers[size++] = lenghtofSequence;
			}
		// продължаваме със следващата поредица,ако има такава
		lenghtofSequence = 0;
		}
	}
	// накрая може да завършим случайно с 1-ца,затова се подсигуряваме
	// да проверим и последната поредица
	if (isPrime(lenghtofSequence))
		primeNumbers[size++] = lenghtofSequence;
	// време за отпечатване на резултата
	cout << "There are " << size << " prime-length platforms. Their lenghts:";
	for (int i = 0; i < size; i++)
	{
		cout << " ";
		cout << primeNumbers[i];
	}
	cout << "." << endl;
}
// 4)
void newPlatforms(int sequence[], int len)
{
	// брояч за новите платформи
	unsigned newPlatform = 0;
	// брояч за дължина на платформите
	unsigned totalLenght = 0;
	// брояч за 0ли
	unsigned countofZeroes = 0;
	// булева,която ще ни казва дали вече сме си създали платформа
	bool isExistPlatform = false;
	for (int i = 0; i < len; i++)
	{
		// ако сме на 0
		if (sequence[i] == 0)
		{
			// дигаме ги
			countofZeroes++;
			// и ако вече сме направили 4-та 0
			if (countofZeroes > 3)
			{
				// следим дали не е минала втората поредна четворка 0,ако е минала
				// няма нужда да правим платформа,защото ние вече разполагаме
				// с такава,затова прескачаме иф-а и дигаме само дължината
				if (!isExistPlatform)
				{
					newPlatform++;
					isExistPlatform = true;
					totalLenght++;
				}
				if (countofZeroes > 7)
					totalLenght++;
			}
		}
		// попаднали сме на 1-ца и всичко започва от начало
		else
		{
			countofZeroes = 0;
			isExistPlatform = false;
		}
	}
	// остана само да изпринтим резултата
	cout << "Mario needs " << newPlatform << " new platforms with total lenght " << totalLenght << endl;
}
int main()
{
	srand(time(0));
	int sequence[MAX_SIZE];
	// предварително дефинирано трасе
	int definedRoute[6] = { 1,1,0,1,1,1 };
	// дължина на трасето
	int len;
	// ограничения
	do
	{
		cin >> len;
	} while (len > MAX_SIZE);
	// ако е валидно число,тогава потребителят въвежда от конзолата трасето
	if (len > 0)
	{
		for (int i = 0; i < len; i++)
			cin >> sequence[i];
	}
	// ако е невалидно
	else if (len == 0)
	{
		// използвам предварително дефинираното трасе в програмата ми
		// и го печатам на терминала
		len = 6;
		for (int i = 0; i < len; i++)
			sequence[i] = definedRoute[i];
		print(sequence, len);
	}
	// ако дължината е по-малка от 0
	else
	{
		// трябва аз да си генерирам свое трасе,с което супер Марио да 
		// продължи своята тренировка
		do
		{
			len = rand() % MAX_SIZE;
		} while (len <= 9);
		for (int i = 0; i < len; i++)
		{
			sequence[i] = rand() % 2;
		}
		// разбира се,трябва да изпринтя трасето
		print(sequence, len);
	}
	// 1)
	theLongestTraining(sequence,len);
	// 2)
	theLongestSequence(sequence, len);
	// 3)
	findPrimesSequence(sequence, len);
	// 4)
	newPlatforms(sequence, len);
	// може ли мнение
	return 0;
}
