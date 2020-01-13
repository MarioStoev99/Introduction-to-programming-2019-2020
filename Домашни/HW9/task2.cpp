#include <iostream>

using namespace std;
const size_t MAX_SIZE = 128;
// булева функция,която казва дали сме на буква
bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}
// името на директорията може да съдържа само малки малки и главни букви,цифри и 
// символа _,като може да започва само с буква
bool isallowableSymbol(char c,char prevSymbol)
{
	// задължителна проверка дали предишният символ е чертичка
	if (prevSymbol == '/' || prevSymbol == '\\')
	{
		// ако е кърънт символа трябва задължително да е буква
		if (isLetter(c))
			return true;
		else
			return false;
	}
	else
	{
		// допустими символи за името на директорията
		if (isLetter(c))
			return true;
		if (c == '_')
			return true;
		if (c >= '0' && c <= '9')
			return true;
	}
	return false;
}
// няма да ползвам функции от библиотеката,сам ще си ги напиша,за да ги упражня
// първата такава е за намиране на дължината.Докато не сме стигнали нулевия байт
// просто увеличавам променливата,накрая връщам резултата
unsigned myStrlen(const char* str)
{
	unsigned count = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
// Конкатенация на стрингове,взимам дължината на първият стринг и там,където е нулевият
// байт започвам да конкатенирам втория.Разбира се, накрая не се забравя символа
// за край на низа.Тази функция се ползва,за криптиране на данните.
void myStrcat(char* text1, const char* text2)
{
	unsigned len_text1 = myStrlen(text1);
	for (size_t i = 0; text2[i] != '\0'; i++)
	{
		text1[len_text1++] = text2[i];
	}
	text1[len_text1] = '\0';
}
// още една стандартна функция,копирам всички символи от втория в първия и накрая слагам
// нулевия байт
void myStrcpy(char* text1, const char* text2)
{
	size_t i;
	for (i = 0; text2[i] != '\0'; i++)
	{
		text1[i] = text2[i];
	}
	text1[i] = '\0';
}
// compare функция,самоче мен ще ме интересува в text1 низа,който започва с .(ехе),
// а не целият str,затова в параметрите съм добавил к,с което ще знам от коя позиция
// започва точката и сравнението ще върви от нея до края на низа.Например : 
// \Home\Data\game.exe
// .exe
// ще сравни .ехе с .ехе и ще върне 0,защото са равни
int myStrcmp(const char* text1, const char* text2,size_t k)
{
	// и сега броячът,който ще започва от 0 за типовете файлове
	size_t j = 0;
	// както и i,който ще започва от к-тата позиция на str
	size_t i;
	// при първа разлика ще излезе от фор-а
	for (i = k; text1[i] != '\0' && text1[i] == text2[j]; i++)
	{
		j++;
	}
	// и ще върне разликата на двете,тази функция връща -1,0,1.Магията тук е,че ще
	// излъжем компилатора като я cast-нем към int тази разлика.
	return (int)(text1[i] - text2[j]);
}
// функция ,която ще запази в матрица всичките видове файлове.
void transferWords(char extensions[][MAX_SIZE], char* str,size_t& k,unsigned number)
{
	size_t j;
	for (j = 0; str[j] != '\0'; j++)
	{
		extensions[k][j] = str[j];
	}
	// за всеки вид файл трябва да има нулев байт
	extensions[k][j] = '\0';
	k++;
}
// функция,която за всяко изречение ще търси дали в extension се съдържа типа файл
bool isvalidExtension(char* str, char cloud[][MAX_SIZE],char extension[][MAX_SIZE],size_t i,unsigned number,unsigned& index)
{
	// броят на всички видове файлове е number
	for (size_t k = 0; k < number; k++)
	{
		// търсим 2 еднакви неща
		if (myStrcmp(str, extension[k], i) == 0)
		{
			// и ,ако ги намерим изречението е стабилно за нашия облак и можем да
			// го копираме
			myStrcpy(cloud[index], str);
			// дигаме индекса за следващата квота
			index++;
			return true;
		}
	}
	// в противен случай не сме намерили нашия тип файл в extension
	return false;
}
int main()
{
	// облакът
	char cloud[MAX_SIZE][MAX_SIZE];
	// мястото ,където ще съхранявам видовете файлове
	char extensions[MAX_SIZE][MAX_SIZE];
	// помощен масив,който ще ми свърши работа на 2 места
	char str[MAX_SIZE];
	// променлива за типовете файлове
	unsigned number;
	// положително,остава да зачеркнем и нулата,ако бяхме в дискретната математика
	// нямаше да я зачертаваме
	do
	{
		cout << "Number of extensions : ";
		cin >> number;
	} while (number == 0);
	// ще помогне за вкарването на видовете файлове в матрицата
	size_t k = 0;
	// запазвам в матрицата видовете файлове
	for (int i = 0; i < number; i++)
	{
		cout << "-Enter file extension: ";
		// ей тук имах малък проблем.Имаше някакъв магически нов ред,който така и не
		// разбрах откъде идва.Все пак ми казаха на упражнението,че по този начин 
		// може да бъде елиминиран
		char c = cin.get();
		if (c != '\n') 
			cin.putback(c);
		cin.getline(str,MAX_SIZE);
		transferWords(extensions, str, k, number);
	}
	// безкраен цикъл,потребителят решава кога да спре програмата
	while (true)
	{
		cout << "Add file by path: ";
		char c = cin.get();
		if (c != '\n') 
			cin.putback(c);
		cin.getline(str, MAX_SIZE);
		// символ за [y | n] 
		char symbol;
		unsigned index = 0;
		// променлива дали сме намерили старта
		bool start = false;
		// ще запазя в променлива стартовия символ,защото ще проверявам напред дали
		// само с него се работи в низа,а предишен символ е ,за да гледам дали
		// директорията започва с буква,ако предишният символ е / или \\

		char startSymbol, previousSymbol;
		for (int i = 0; str[i] != '\0'; i++)
		{
			char c = str[i];
			// ако сме на стартова позиция
			if (!start)
			{
				//проверка на първи символ
				if (c == '/' || c == '\\')
				{
					// запазвам стартовия символ
					startSymbol = c;
					// и казвам,че повече не искам да влизам тук
					start = true;
				}
				// в противен случай не съм намерил това,което искам и приключвам с този низ
				else
				{
					cout << str[i] << endl;
					cout << " -  error! Wrong input. Try again." << endl;
					break;
				}
			}
			// проверки дали работя с едно и също име.Ако текущият символ е /
			else if (c == '/')
			{
				// и той се различава от стартовия символ,то приключваме с този низ
				if (c != startSymbol)
				{
					cout << " -  error! Wrong input. Try again." << endl;
					break;
				}
			}
			// същата логика за втората възможност
			else if (c == '\\')
			{
				if (c != startSymbol)
				{
					cout << " -  error! Wrong input. Try again." << endl;
					break;
				}
			}
			// ако сме стигнали точка имаме две възможности
			else if (c == '.')
			{
				// да проследим дали типа файл го има в нашата матрица и ,ако го има
				// значи сме готови и го запазваме в облака
				if (isvalidExtension(str, cloud, extensions, i, number, index))
					cout << " - Success! File successfully uploaded!" << endl;
				// в противен случай не го припознава и низа гърми
				else
					cout << " - error! The cloud does not recognise this file extension. Try agaian." << endl;
				break;
			}
			// имаме случай,в който предишният символ е / || \\.Тогава,ако текущият символ
			// не е буква,то имаме някакъв проблем
			else if (!isallowableSymbol(c, previousSymbol))
			{
				//cout << str[i] << endl;
				cout << " -  error! Wrong input. Try again." << endl;
				break;
			}
			// накрая текущият символ става предишен
			previousSymbol = c;
		}
		// питаме потребителя дали иска добавяне на нов файл
		cout << "Do you want to add more files? [y | n]." << endl;
		// трябва да се знае,че възможностите са 2 - yes || no
		do
		{
			cin >> symbol;
		} while (symbol != 'n' && symbol != 'y');
		// ако потребителя каже не ,приключваме
		if (symbol == 'n')
			return 0;
	}
	// може ли мнение 
}
