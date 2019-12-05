#include <iostream>
using namespace std;

int main()
{
	unsigned n;
	// проверчица дали сме в интервала [1,31];
	do
	{
		cin >> n;
	} while (n == 0 || n > 31);
	unsigned cardNumber;
	//ще събирам единици в този каунт
	unsigned count = 0;
	unsigned sequence;
	int prevcardNumber = 0;
	unsigned mask = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> cardNumber;
		// Ще влезе само при първо завъртане на цикъла
		if (i == 0)
		{
			sequence = 1;
			count++;
		}
		// за i >= 1 ще влиза в else
		else
		{
			// ако текущото число ми е по-голямо от предходното добавям 0 в сикуенса и му правя
			// включващо или ,за да добавя единицата
			if (cardNumber >= prevcardNumber)
			{
				sequence = (sequence << 1);
				sequence |= mask;
				count++;
			}
			//в противен случай вкарвам 0 в сикуенса
			else
			{
				sequence = (sequence << 1);
			}
		}
		prevcardNumber = cardNumber;
	}
	// принтя поредицата
	for (int i = n - 1; i >= 0; i--)
	{
		cout << ((sequence >> i) & 1) << " ";
	}
	cout << endl;
	// проверка дали числото е четно или нечетно,ако е нечетно взимам единицата в средата
	if (count % 2 != 0)
	{
		count /= 2;
		count++;
	}
	// в противен случай взимам лявата
	else
		count /= 2;
	// създавам си каунтъри,които да движат сумите от лявата
	// и дясната страна на медианната единица
	unsigned rightsidecountofzeroes = 0;
	unsigned leftsidecountofzeroes = 0;
	// докато сикуенса ми е различен от 0 взимам винаги най-младшия бит
	while (sequence)
	{
		unsigned short lastDigit = ((sequence >> 0) & 1);
		if (count != 0) // ако съм преди междинната единица
		{
			// ако срешна 0 вдигам нулите отдясно
			if (lastDigit == 0)
				rightsidecountofzeroes++;
			// в противен случай съм на единица и трябва да ги свалям ,докато
			// не съм стигнал медианната
			else
				count--;
		}
		// в противен случай ще вдигам нулите отляво,защото вече ше съм минал
		// медианната единица
		else
		{
			if (lastDigit == 0)
				leftsidecountofzeroes++;
		}
		// шифтвам и продължавам работа със следващия елемент
		sequence = (sequence >> 1);
	}
	// накрая изкарваме на терминала нулите,които са повече,както и техният брой
	if (rightsidecountofzeroes > leftsidecountofzeroes)
		cout << "Right side : " << rightsidecountofzeroes;
	else if (rightsidecountofzeroes < leftsidecountofzeroes)
		cout << "Left side : " << leftsidecountofzeroes;
	else
		cout << "Both sides : " << rightsidecountofzeroes;
	// Може ли мнение на второ лесно домашно,както и на текущото :)
	return 0;
}
