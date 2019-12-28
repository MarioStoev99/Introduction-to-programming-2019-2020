#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// вместо да пиша цялото 19-цифрено число просто функцията ще го сметне и ще го 
// изпрати на моя ключ,ще работим с 64-битови числа,т.е от 2^60 дo 2^63
unsigned long long Pow(unsigned pow)
{
	unsigned long long num = 1;
	while (pow)
	{
		num *= 2;
		pow--;
	}
	return num;
}
// функцийка,която генерира 64-битови числа
unsigned long long generateDigit(unsigned long long left,unsigned long long right)
{
	unsigned long long x = 0;
	do
	{
		for (int i = 0; i < 64; i++)
		{
			x = x * 2 + rand() % 2;
		}
	// ако случайно числото не е в интервала,генерираме ново такова
	} while (x < left || x > right);
	return x;
}
// стандартен binarySearch,който ще взима средата 
void binarySearch(unsigned long long key)
{
	// интервалът,в който ще търсим числото
	unsigned long long left = Pow(60);
	unsigned long long right = Pow(63) - 1;
	// с този каунт ще пресмятам опитите да бъде намерен ключът
	unsigned count = 0;
	while (left < right)
	{
		// открих мотиката в листата,за която споменахте
		unsigned long long mid = left / 2 + right / 2;
		// ако сме намерили ключът
		if (mid == key)
		{
			// принтим го,дигаме опитите
			cout << mid << endl;
			count++;
			// и изкарваме резултата
			cout << "Po standartniq binarySearch kluchyt e nameren ot " << count << " opita." << endl;
			return;
		}
		// ако ключът се намира отдясната част на средата,скъсяваме интервала отляво надясно
		if (mid < key)
		{
			// принтим стойностите от самите опити
			cout << mid << " ";
			left = mid + 1;
			// дигаме опитите
			count++;
		}
		// в противен случай отдясно наляво
		else
		{
			//принтим стойностите от самите опити
			cout << mid << " ";
			right = mid;
			//дигаме опитите
			count++;
		}
	}
	return;
}
// рандомизираният байнъриСърч
void randombinarySearch(unsigned long long key)
{
	// същите начални условия
	unsigned count = 0;
	unsigned long long left = Pow(60);
	unsigned long long right = Pow(63) - 1;
	while (left < right)
	{
		// разликата е,че вече в този интервал взимаме рандъм число и с него 
		// cut-ваме самия интервал
		unsigned long long random = generateDigit(left,right);
		if (random == key)
		{
			count++;
			cout << random << endl;
			cout << "Po randomiziranoto tursene kluchyt e nameren ot " << count << " opita." << endl;
			return;
		}
		if (random < key)
		{
			count++;
			cout << random << " ";
			left = random + 1;
		}
		else
		{
			count++;
			cout << random << " ";
			right = random;
		}
	}
	return;
}
int main()
{
	srand(time(nullptr));
	// създаваме си рандъм ключ
	long long unsigned key = generateDigit(Pow(60),Pow(63) - 1);
	randombinarySearch(key);
	binarySearch(key);
	// Ами статистиката показва,че с рандомизирания алгоритъм 3,4-пъти по-бързо се открива
	// този ключ,отколкото със средата
	// може ли мнение,ако е необходимо :)
	return 0;
}
