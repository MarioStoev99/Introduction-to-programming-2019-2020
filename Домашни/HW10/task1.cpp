#include <iostream>
using namespace std;
int countofDigits(int number,int count)
{
	// дъното ще бъде ,когато сме ударили 0-лата,ако не се лъжа това беше опашкова
	// рекурсия,т.е още при самото разгъване на стековите рамки дигаме каунта,а при
	// сгъването просто подхвърляме резултата
	if (number == 0)
		return count;
	else 
		// делим и увеличаваме,докато нъмбър не стане 0
		return countofDigits(number / 10, count + 1);
}
// Идеята на решението ми е следната
// 1234 и отделно 5
// 4 != 5 -> да
// 3 != 5 -> да
// 2 != 5 -> да
// 1 != 5 -> да
// ок cloningNumber става 0 ,време е да вземем последната цифра на 1234 и да я 
// сравним с останалите 3 ,правим го
// 1234 % 10 = 4 , 1234 / 10 = 123
// започват проверките
// 3 != 5 -> да
// 2 != 5 -> да
// 1 != 5 -> да
// ...
// накрая ше остане само 1 делим го на 10,е даде,ама в следващата стекова рамка
// двата каунта ще станат 0 и съответно сме ударили дъното,започват да се трият стековите
// рамки и накрая връща,че няма повтарящо се число,ако случайно пък по време на проверките
// срещне две числа,които са равни,функцията връща Йес и всичко в стека започва да се трие
void haveEqualDigits(unsigned lastDigit,unsigned cloningNumber,unsigned number,unsigned count,unsigned currentCount)
{
	if (count == 0 && currentCount == 0)
	{
		cout << "No";
		// този ретърн е жизнено важе,с него функцията спира 
		return;
	}
	if (cloningNumber % 10 == lastDigit)
	{
		cout << "Yes";
		return;
	}
	// време да заредим клонинг нъмбъра
	if (currentCount == 0)
		haveEqualDigits(number % 10, number / 10,number / 10, count - 1, count - 1);
	// иначе той си е зареден и просто махаме последната цифра
	else
		haveEqualDigits(lastDigit, cloningNumber / 10,number, count, currentCount - 1);
}
int main()
{
	// естествено число
	unsigned number;
	// без 0-лата
	do
	{
		cin >> number;
	} while (number == 0);
	// брояч,който ще ми помогне с решаването на задачата,ще преброя от колко цифри се
	// състои числото,като няма да ползвам цикъл,ами ще го направя рекурсивно
	int count = countofDigits(number, 0);
	// извикваме функцията 
	haveEqualDigits(number % 10,number / 10,number / 10, count, count - 1);
	return 0;
}
