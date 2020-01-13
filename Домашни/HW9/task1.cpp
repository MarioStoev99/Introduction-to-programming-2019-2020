#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// задачата ще я направя с мои функции,а не с тези от библиотеките
// максималният брой !
const size_t MAX_SIZE = 10;
// създаване на динамичен масив от символи
char* create(size_t size)
{
	char* str = new (nothrow) char[size];
	return str;
}
// връщаме ресурсите
void _delete(char* expression)
{
	delete[] expression;
}
// намиране на дължината на низ
int myStrlen(const char* str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}
// копираме втория низ в първия
void myStrcpy(char* temp, const char* str)
{
	size_t i;
	for (i = 0; str[i] != '\0'; i++)
		temp[i] = str[i];
	// нулевият байт е важен
	temp[i] = '\0';
}
// функция,която ще конкатенира !
void concatSigns(char* temp,unsigned lenofSign)
{
	// взимам дължината
	int len = myStrlen(temp);
	int i;
	for (i = 0; i < lenofSign; i++)
	{
		// и започвам от нея да лепя !
		temp[len++] = '!';
	}
	// накрая залепям нулевия байт
	temp[len] = '\0';
}
// тук ппц функцията е стандартната,единственото,което съм добавил е интервалче
void myStrcat(char* text1, const char* text2)
{
	// взимам дължината,защото от нея ще започвам да конкатенирам
	int text1Len = myStrlen(text1);
	// добавям интервал
	text1[text1Len++] = ' ';
	// от съображение за сигурност си залепям нулевия байт
	text1[text1Len] = '\0';
	int i;
	// и вече както попринцип продължавам да конкатенирам
	for (i = 0; text2[i] != '\0'; i++)
		text1[text1Len++] = text2[i];
	text1[text1Len] = '\0';
}
int main()
{
	char* expression = nullptr;
	// ще ползвам ранд функция,понеже никъде в примера не видях числа по конзолата
	// съответно по подразбиране търсенето е рандомизирано
	srand(time(nullptr));
	// дължина на !
	unsigned lenofSign;
	// колко изречения ще има на конзолата
	unsigned N;
	// речници с думи,които не могат да бъдат променяни,разбира се,по всяко време думите и дължината могат
	// да бъдат сменени и да се работи с други такива,аз ще използвам тези от задачата
	const char* exclamations[] = { "Shok","Skandal","Nechuvana naglost" };
	unsigned lenofExclamations = 3;
	const char* object[] = { "rqpa","baba","kmet","bager","sklad" };
	unsigned lenofObjects = 5;
	const char* subject[] = { "rqpa","baba","kmet","bager" };
	unsigned lenofSubjects = 4;
	const char* action[] = { "sgazi","zadiga","namiga na","precakva","tarashi" };
	unsigned lenofActions = 5;
	// потребителят въвежда брой на изреченията и ограничение,разбира се
	do
	{
		cout << "Enter number of headings : ";
		cin >> N;
	} while (N == 0);
	for (int i = 0; i < N; i++)
	{
		// интервалите на всяко изречение,за които трябва да се грижа са 3,затова
		// започвам с 3 
		unsigned size = 3;
		// 1 стъпка - изберете по една дума за всяка от четирите категории
		unsigned remainderofExclamations = rand() % lenofExclamations;
		size += myStrlen(exclamations[remainderofExclamations]);
		unsigned remainderofObject = rand() % lenofObjects;
		size += myStrlen(object[remainderofObject]);
		unsigned remainderofSubject = rand() % lenofSubjects;
		size += myStrlen(subject[remainderofSubject]);
		unsigned remainderofAction = rand() % lenofActions;
		size += myStrlen(action[remainderofAction]);
		// втора стъпка - изберете брой удивителни
		do
		{
			lenofSign = rand() % 11;
		} while (lenofSign > MAX_SIZE || lenofSign < 3);
		size += lenofSign;
		// трета стъпка - заделете динамично масив,който е точно толкова голям,че
		// да събере заглавието и + 1 заради нулевия байт
		expression = create(size + 1);
		// провечица
		if (!expression)
		{
			cout << "not memory enought";
			return 0;
		}
		// четвърта стъпка - копирайте думите в масива 
		myStrcpy(expression, exclamations[remainderofExclamations]);
		concatSigns(expression, lenofSign);
		myStrcat(expression, object[remainderofObject]);
		myStrcat(expression, action[remainderofAction]);
		myStrcat(expression, subject[remainderofSubject]);
		// и го изведете на екрана
		cout << expression << endl;
		// пета стъпка - освободете паметта
		_delete(expression);
		expression = nullptr;
	}
	return 0;
}
