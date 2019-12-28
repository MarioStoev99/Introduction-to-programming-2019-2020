#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// 52 карти,жокерите няма да ги ползваме засега
const size_t MAX_SIZE = 52;
// функция,която ще вмъква елемент в редица и ще избутва до края елементите,там където
// има референции е ,за да държа в течение външния свят
void insert(int* arr, unsigned& size,unsigned& startingPos,unsigned card)
{
	size++;
	for (startingPos; startingPos < size; startingPos++)
	{
			arr[size - 1] = arr[startingPos];
			arr[startingPos] = card;
			card = arr[size - 1];
	}
}
void sortDeck(int* arr, unsigned& size,unsigned card)
{
	// слагам я фоулс и ,ако не се промени,означава,че елементът не си е намерил мястото
	// и ще го сложа най-накрая
	bool findLargest = false;
	// последните 2 цифри на картата
	int remainderofCard = card % 100;
	for (unsigned i = 0; i < size; i++)
	{
		// ще влезнем при първо врътване на фор-а
		if (size == 0)
		{
			findLargest = true;
			arr[size++] = card;
		}
		int current = arr[i];
		// взимам текущите последни 2 числа
		int  curr_remainder = current % 100;
		// малко частни случаи за асата
		if (remainderofCard == 01)
		{
			if (curr_remainder == 01)
			{
				// ако стигнем до тук означава,че картата за вмъкване и текущата в тестето
				// са еднакви и трябва да проверим боята
				unsigned paintofCard = card / 100;
				unsigned paintofCurrent = current / 100;
				// ако първото е например спатия,а второто пика,то я вмъкваме в дестето
				if (paintofCard > paintofCurrent)
				{
					insert(arr, size, i, card);
					// отчитаме,че сме вмъкнали карта
					findLargest = true;
				}
			}
			// свършили сме си работата
			continue;
		}
		// без този случай 313 май ще го изпрати след 401,затова е важен,иначе 
		// проверявам дали текущия
		if (curr_remainder == 01)
		{
			if (remainderofCard == 01)
			{
				// ако и двете са 01 им взимам боята
				unsigned paintofCard = card / 100;
				unsigned paintofCurrent = current / 100;
				// сравнявам им боите
				if (paintofCard > paintofCurrent)
				{
					// ако картата на потребителя е с по-нисък приоритет я вмъкваме
					//в тестето
					insert(arr, size, i, card);
					findLargest = true;
				}
			}
			// в противен случай картата на потребителя е различна от 01
			else
			{
				// отново вмъкваме
				findLargest = true;
				insert(arr, size, i, card);
			}
			continue;
		}
		// ако текущата карта е с повече сила от тази на потребителя я вмъкваме
		if (curr_remainder > remainderofCard)
		{
			findLargest = true;
			insert(arr, size, i,card);
		}
		// ако са с равни точки
		if (curr_remainder == remainderofCard)
		{
			// гледаме боята
			unsigned paintofCard = card / 100;
			unsigned paintofCurrent = current / 100;
			// спатия,каро,купа,пика
			if (paintofCard > paintofCurrent)
			{
				findLargest = true;
				insert(arr, size, i, card);
			}
		}
	}
	// както казах по-нагоре,ако случайно не съм намерил място на картата я пращам накрая
	if (!findLargest)
		arr[size++] = card;
}
// полезна функцийка за а),с която се следи всяка стъпка
void print(const int* arr, const unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
// принт функция за б)
void print(const int* arr)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
// функция ,която меша тестето
void mixDeck(int* sortdeckArray)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		unsigned randomElement1 = rand() % 52;
		unsigned randomElement2 = rand() % 52;
		unsigned temp = sortdeckArray[randomElement1];
		sortdeckArray[randomElement1] = sortdeckArray[randomElement2];
		sortdeckArray[randomElement2] = temp;
	}
}
// функция,която слапва 2 елемента
void mySwap(int* sortdeckArray,unsigned i,unsigned j)
{
	int temp = sortdeckArray[i];
	sortdeckArray[i] = sortdeckArray[j];
	sortdeckArray[j] = temp;
}
// алгоритъм,който ще сортира тестето.Алгоритъмът е стабилен,без големи прескачания,
// най-тежкият елемент отива в края,предимството пред останалите алгоритми е,че разбира
// кога масивът е сортиран
void bubbleSort(int* sortdeckArray)
{
	bool changed = false;
	unsigned sorted = 0;
	do
	{
		// започваме с фоулс и,ако тя остане непроменена след края на фор цикъла,то
		//масивът вече е сортиран
		changed = false;
		for (unsigned i = MAX_SIZE - 1; i > sorted; i--)
		{
			// взимаме последните 2 цифри на масива
			unsigned remainderCurrent = sortdeckArray[i] % 100;
			unsigned remainderPrevious = sortdeckArray[i - 1] % 100;
			// няколко частни случаи,ако елементите ни са с остатъци 01 
			if (remainderCurrent == 01 && remainderPrevious == 01)
			{
				// взимаме боите на двете карти
				unsigned paintCurrent = sortdeckArray[i] / 100;
				unsigned paintPrevious = sortdeckArray[i - 1] / 100;
				// ако например спатията е след пиката,трябва да ги разменим
				if (paintCurrent > paintPrevious)
				{
					mySwap(sortdeckArray, i, i - 1);
					// в задачата се иска при всяко местене на карти да показвам
					// коя къде се мести
					print(sortdeckArray);
					// направили сме размяна,трябва да се отчете
					changed = true;
				}
				// за да не стават проблеми приключваме с тази итерация
				continue;
			}
			// ако пък текущият елемент е 01,а предишният е нещо различно от 01,то
			// няма нужда да правим нещо,затова приключваме с итерацията
			if (remainderCurrent == 01)
				continue;
			// ако пък е обратното трябва вече да ги разменим
			if (remainderPrevious == 01)
			{
				mySwap(sortdeckArray, i, i - 1);
				print(sortdeckArray);
				changed = true;
				continue;
			}
			// Ако последните 2 цифри са различни и в същото време е нарушена тяхната
			// подредна.Това е достатъчно условие,което ни устройва и можем да разменим елементите
			if (remainderCurrent < remainderPrevious)
			{
				mySwap(sortdeckArray, i, i - 1);
				print(sortdeckArray);
				changed = true;
			}
			// Ако са равни последните 2 цифри
			if (remainderCurrent == remainderPrevious)
			{
				// сравнението става с бои
				unsigned paintCurrent = sortdeckArray[i] / 100;
				unsigned paintPrevious = sortdeckArray[i - 1] / 100;
				// същата продедура
				if (paintCurrent > paintPrevious)
				{
					mySwap(sortdeckArray, i, i - 1);
					print(sortdeckArray);
					changed = true;
				}
			}
		}
		++sorted;
	} while (changed);
}
int main()
{
	// онази вълшебна нула казаха ,че била поинтър към нищото на упражнението
	srand(time(nullptr));
	// ще ползвам масив,защото имам 52 карти да помня
	int arr[MAX_SIZE];
	// неразопаковано чисто ново тесте
	int sortdeckArray[MAX_SIZE] = { 402,302,202,102,
							        403,303,203,103,
									404,304,204,104,
									405,305,205,105,
									406,306,206,106,
									407,307,207,107,
									408,308,208,108,
									409,309,209,109,
									410,310,210,110,
									411,311,211,111,
									412,312,212,112,
									413,313,213,113,
									401,301,201,101 };
	unsigned size = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
	// потребителят казва кои са картите
		unsigned temp;
		cin >> temp;
		// вкарваме я в масива
		sortDeck(arr, size, temp);
		// полезна функция,с която се следи всяка карта къде отива
		//print(arr, size);
	}
	// с тази функция ще ги разджуркаме
	mixDeck(sortdeckArray);
	// после ще покажем как сме ги разджуркали
	print(sortdeckArray);
	// сортираме
	bubbleSort(sortdeckArray);
	// Попринцип не е нужен,защото в а) подточка се иска масивът да бъде сервиран
	// сортирано,и когато потребителят въведе 52-рата карта тестето ще бъде сортирано
	// и автоматично може да се работи с него в б).Аз обаче си подходих с втори,което 
	// не мисля,че е грешно.Разликата между двете сортировки,които направих е,че 
	// при първата теглейки карта аз вече ще знам къде ще отиде и,когато съм на 32-рата
	// например масивът ще бъде сортиран.Докато вторият подход е,че слагам 52 карти
	// на масата подредени,хващам най-последната и започвам да я сравнявам с предходните.
	return 0;
}
