#include <iostream>
#include <cmath>
using namespace std;
// функция  за абсолютна стойност
int myAbs(int num)
{
	if (num < 0)
		return -num;
}
// намиране на n!
double factoriel(int num)
{
	// започвам от 1-цата,защото тя е неутралният елемент при умножението
	// ако започвахме от 0,щяхме да се завъртим в кръг
	double sum = 1;
	while (num != 1)
	{
		sum *= num;
		num--;
	}
	return sum;
}
// понеже в точка 8) се подава дабъл,функцията от 3) няма да ми свърши работа
double powforDouble(double a, unsigned b)
{
	// 0 на която и да е степен е 0
	if (a == 0)
		return a;
	// 1 на която и да е степен е 1
	else if (a == 1)
		return a;
	//ако сме дигнали числото на първа степен си остава същото
	else if (b == 1)
		return a;
	//в противен случай търсим нашето число повдигнато на степен б
	else
	{
		double sum = 1.0;
		while (b)
		{
			sum *= a;
			b--;
		}
		return sum;
	}
}
int sumofDigits(int number, unsigned numberofSystem)
{
	int sum = 0;
	// ако искаме да получим числото в двоичен запис
	if (numberofSystem == 2)
	{
	// докато не стигнем до старшия бит..Тук не е фатално,че шифтваме
	// числото намбър,защото реално ние шифтване неговото копие :)
		while (number)
		{
			// взимаме последния бит и му прилагаме побитово и с 1-ца
			int lastBit = ((number >> 0) & 1);
			sum += lastBit;
			// следващ бит
			number = (number >> 1);
		}
	}
	// може потребителят да иска числото да бъде сметнато в осмична
	else if (numberofSystem == 8)
	{
		// представете си числото 1212,то е 2*1 + 1*10 + 2*100 + 1*1000;
		// това съм се постарал да опиша в while цикъла
		int temp = 1;
		while(number)
		{
			//взимам остатъка по модул 8
			int remainder = number % 8;
			sum += temp * remainder;
			number /= 8;
			temp *= 10;
		} 
	}
	// по подразбиране сме в шестнайсетична ,тук е най-просто.Взимаме само остатъка
	else
	{
		while (number)
		{
			int remainder = number % 16;
			sum += remainder;
			number /= 16;
		}
	}
	return sum;
}
//НОД
int gcd(int num1,int num2)
{
	if (num1 > 0 && num2 > 0)
	{
		// Ако са равни няма нужда да правим излишни проверки
		if (num1 == num2)
			return num1;
		else
		{
			// правим проверка кое число е по-голямо
			unsigned _gcd;
			if (num1 > num2)
				_gcd = num2;
			else
				_gcd = num1;
			while (_gcd)
			{
				// ако сме намерили такъв делител сме готови
				if (num1 % _gcd == 0 && num2 % _gcd == 0)
					return _gcd;
				// ако не продължаваме да го търсим
				else
					--_gcd;
			}
		}
	}
	// искаме числата да са положителни,в този случай попадаме,ако num1 и num2 са 0-ли
	else
		return -1;
}
// подобно на горната функция Pow,с разликата,че тук подаваме като
// аргумент инт ,а не дабъл
int myPow(int a, int b)
{
	if (b > 0)
	{
		if (a == 0)
			return a;
		else if (a == 1)
			return a;
		else if (b == 1)
			return a;
		else
		{
			int sum = 1;
			while (b)
			{
				sum *= a;
				b--;
			}
			return sum;
		}
	}
	// ако b == 0;
	else
		return -1;
}
// зелената функция
bool isgreenDigit(int num)
{
	// ако променя копието накрая няма да мога да проверя резултата си дали е равен
	// затова си правя нова променлива
	int cloningNum = num;
	int sum = 0;
	while (cloningNum)
	{
		// взимаме последната цифра
		int lastDigit = cloningNum % 10;
		cloningNum /= 10;
		// и сумираме с нашата функция,която си направихме
		sum += myPow(lastDigit, 3);
	}
	// Ако е сумата е равна на подаденото число като аргумент,то числото е зелено
	return sum == num;
}
// само 4 или 5 числа май успях да мерна,че са такива и то от 1 до 1000
int sumofgreenDigits(int M, int N)
{
	int sum = 0;
	// ако интервалът е обърнат разменяме стойностите на променливите,
	// мисля,че е по-добре така вместо да копирам един и същи код :)
	if (M > N) 
	{
		int temp = M;
		M = N;
		N = temp;
	}
	for (int i = M; i <= N; i++)
	{
		// използваме нещо познато вече
		if (isgreenDigit(i))
		{
			sum += i;
		}
	}
	return sum;
}
// червено ли е числото
bool isredDigit(int num)
{
	// пак ще взимаме допълнителна променлива,защото копието ще ни трябва
	int cloningNum = num;
	int sum = 0;
	// събираме всички цифри на едно място
	while (cloningNum)
	{
		int lastDigit = cloningNum % 10;
		sum += lastDigit;
		cloningNum /= 10;
	}
	// и най-важното ,ако числото се дели без остатък,то е червено
	return num % sum == 0;
}
// разликата на зелени и червени
int sumofgreeenredDigits(int M, int N)
{
	// правим си две суми,едната ще събира червените,другата зелените
	int sumofgreenDigits = 0;
	int sumofredDigits = 0;
	// същата процедура като понагоре с интервала
	if (M > N)
	{
		int temp = M;
		M = N;
		N = temp;
	}
	for (int i = M; i <= N; i++)
	{
		// ако числото е червено го прибавяме
		if (isredDigit(i))
		{
			sumofredDigits += i;
		}
		// ако е зелено го прибавяме
		if (isgreenDigit(i))
		{
			sumofgreenDigits += i;
		}
	}
	// правим тяхната разлика
	int total = sumofgreenDigits - sumofredDigits;
	// накрая ,ако числото е отрицателно,се включва абсолютната стойност
	// В интерес на истината винаги ще се активира иф-а,защото червените
	// са много повече от зелените
	if (total < 0)
		return myAbs(total);
	else
		return total;
}
// функция за редицата от задача 8)
double sumofLine(double x, int n)
{
	double sum = 0;
	bool collection = false;
	bool start = true;
	// размерът ми е до n*2,защото ще прескачам с 2
	for (int i = 0; i < n * 2; i += 2)
	{
		// ще влезне само първият път,защото започваме с 1-ца
		if (start)
		{
			sum += 1;
			start = false;
			continue;
		}
		// смятам този сложен израз с познати функции
		double temp = powforDouble(x, i) / factoriel(i);
		// ако е време за събиране
		if (collection)
		{
			sum += temp;
			collection = false;
		}
		// в противен случай е време за изваждане
		else
		{
			sum -= temp;
			collection = true;
		}
	}
	// понеже от тази функция ще получаваме стойност за cos съм длъжен
	// да проверим дали тази сума се намира в интервала от [-180;180];
	if (sum >= -1 && sum <= 1)
	{
		return sum;
	}
}
// функция за синус
double _sin(double cos)
{
	double sinX = 1 - cos * cos;
	// Ванака ми позволи да ползвам sqrt.За цели числа мисля,че мога да
	// си направя mySqrt,но за дабъли няма да успея..
	return sqrt(sinX);
}
// функция за тангенс
double _tg(double sin, double cos)
{
	return sin / cos;
}
// функция за котангенс
double _cotg(double sin, double cos)
{
	return cos / sin;
}
int main()
{
	// валидация
	int a, b;
	unsigned long long aboveBorder = 2000000000;
	long long belowBorder = -2000000000;
	do
	{
		cin >> a;
	} while (a > aboveBorder || a < belowBorder);
	do
	{
		cin >> b;
	} while (b > aboveBorder || b < belowBorder);
	cout << myPow(a,b) << endl;
	/*
	cout << sumofDigits(15, 2) << endl;
	cout << sumofDigits(77, 2) << endl;
	cout << sumofDigits(650, 8) << endl;
	cout << sumofDigits(0x01ABCD, 16) << endl;
	cout << gcd(a,b) << endl;
	cout << gcd(84,18) << endl;
	cout << gcd(42, 56) << endl;
	cout << gcd(18, 84) << endl;
	cout << gcd(18, 84) << endl;
	cout << sumofgreenDigits(1, 1000) << endl;
	cout << sumofgreeenredDigits(1000, 1) << endl;
	double cos = sumofLine(-0.10,4);
	cout << cos << endl;
	double sin = _sin(cos);
	cout << sin << endl;
	cout << factoriel(5);
	*/
	// може ли мнение :)
	return 0;
}
