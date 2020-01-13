#include <iostream>
using namespace std;
// създаваме си динамичен масив и връщаме поинтър към тази памет
int* create(size_t size)
{
	int* arr = new(nothrow) int[size];
	return arr;
}
// проверка дали числото е степен на 2-ката при въвеждането от потребителя
bool isPow(int num)
{
	while (num != 1)
	{
		if (num % 2 != 0)
			return false;
		num /= 2;
	}
	return true;
}
//инициализираме стойности в масива
void init(int* arr, unsigned size)
{
	for (size_t i = 0; i < size; i++)
	{
		do
		{
			cin >> arr[i];
		// имаме ограничения,дали е в даден интервал и дали е степен на 2-ката
		} while (arr[i] < 2 || arr[i] > 256 || !isPow(arr[i]));
	}
}
// функция,която ще удвоява размера на динамичния масив.Пращам го по & ,защото
// се създава копие на указател и съответно сайз е по &,за да остане видим за външния свят
void resize(int*& arr,unsigned& size)
{
	// Поискваме от банката
	int* new_arr = new(nothrow) int[size*2];
	// Проверяваме дали банката има толкова пари
	if (!new_arr)
		return;
	// прехвърляме елементите от стария масив в новия
	for (size_t i = 0; i < size; i++)
		new_arr[i] = arr[i];
	// трием старата памет
	delete[] arr;
	// пренасочваме указателя към новия масив
	arr = new_arr;
	// удвояваме сайз
	size *= 2;
}
// намирам позицията на максималния елемент
int findMax(int* arr, unsigned len)
{
	// казвам,че макс ще ми е първият елемент в поредицата
	int max = arr[0];
	// както и на същата позиция
	unsigned pos = 0;
	for (size_t i = 1; i < len; i++)
	{
		// ако намеря по-голям
		if (max < arr[i])
		{
			// запаметявам
			max = arr[i];
			pos = i;
		}
	}
	// връщам позицията
	return pos;
}
// функция за вмъкване на елемент
void insert(int* arr, unsigned& len, unsigned pos)
{
	// ще го разтягам с едно надясно винаги
	len++;
	// избутвам
	for (int i = len - 1; i > pos; i--)
		arr[i] = arr[i - 1];
}
// Ползване на ресурсите от банката
void A(int*& arr, unsigned& size, unsigned& len, unsigned number)
{
	// докато не стане 0
	while (number)
	{
		// взимам индекса на максималния елемент
		unsigned posofmaxElement = findMax(arr, len);
		// проверка дали максималният елемент не е 2
		if (arr[posofmaxElement] != 2)
		{
			// ако не е деля максималния на 2
			arr[posofmaxElement] /= 2;
			// проверявам дали имам заделена памет и ,ако нямам викам ресайз функцията
			if (size == len)
				resize(arr, size);
			// то по-скоро не е вмъкване на елемент,защото аз реално го разтягам и
			// елемента си седи вътре в самия масив,но и така бива
			insert(arr, len, posofmaxElement);
			// намалям броя на разбиванията
			number--;
		}
		// ако стигнем до този случай вече сме си измили ръцете и няма какво да
		// пипаме по масива,в него живеят само 2-ки
		else
		{
			cout << "try again after Hoth." << endl;
			return;
		}
	}
}
// принт функция,която е по-особено форматирана
void P(int* arr, unsigned len)
{
	cout << "[";
	for (size_t i = 0; i < len; i++)
	{
		if (i != len - 1)
			cout << arr[i] << ", ";
		else
			cout << arr[i] << "]";
	}
	cout << endl;
}
// трябва да върнем ресурсите на банката a.k.a операционната система
void _delete(int* arr)
{
	delete[] arr;
}
int main()
{
	// сайз ще играе един вид ролята на MAX_SIZE,а len текущият брой елементи в масива
	unsigned size,len;
	// ограничения
	do
	{
		cin >> size;
	} while (size < 4 || size > 1024);
	len = size;
	// насочваме поинтъра към нищото
	int* arr = nullptr;
	// взимаме ресурси от банката
	arr = create(size);
	// проверка
	if (!arr)
	{
		cout << "Not memory enought";
		return 0;
	}
	// инициализираме някакви стойности в масива
	init(arr, size);
	char c;
	unsigned number;
	// безкраен цикъл
	while (true)
	{
		do
		{
			cin >> c;
			// имаме само 3 възможности,буквата да е A,P или Е.
		} while (c != 'A' && c != 'P' && c != 'E');
		// ако командата е А
		if (c == 'A')
		{
			// ограничение за нъмбър,ако е 0 не правим нищо
			do
			{
				cin >> number;
			} while (number == 0);
			// викаме командата А
			A(arr, size, len, number);
		}
		// P командата
		else if (c == 'P')
		{
			P(arr, len);
		}
		// иначе връщаме кредита на банката
		else
		{
			_delete(arr);
			return 0;
		}
	}
	// може ли мнение
}
