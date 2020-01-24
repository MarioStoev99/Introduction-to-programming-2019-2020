#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
const size_t MAX_SIZE = 1024;
char** createMatrix(int index)
{
	char** matrix = new(nothrow) char* [index];
	return matrix;
}
char* createArr(size_t size)
{
	char* str = new(nothrow) char[size];
	return str;
}
void deleteMatrix(char** matrix, int index)
{
	for (int i = 0; i < index; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
int lenofWords(char* str)
{
	int count = 1;
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ' ')
			count++;
	return count;
}
void myStrcpy(char* str, const char* str1)
{
	int i;
	for (i = 0; str1[i] != '\0'; i++)
		str[i] = str1[i];
	str[i] = '\0';
}
bool isAlpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	if (c == '!')
		return true;
	return false;
}
void dymnamicWords(char* str, char** words)
{
	int brofWords = 0;
	int lenofWord = 0;
	bool searchingLetter = true;
	char* temp;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isAlpha(str[i]))
		{
			lenofWord++;
			if (searchingLetter)
			{
				temp = str + i;
				searchingLetter = false;
			}
		}
		else
		{
			str[i] = '\0';
			words[brofWords] = createArr(lenofWord + 1);
			if (!words[brofWords])
			{
				deleteMatrix(words, brofWords);
				words = nullptr;
				return;
			}
			myStrcpy(words[brofWords],temp);
			brofWords++;
			lenofWord = 0;
			searchingLetter = true;
		}
	}
	words[brofWords] = createArr(lenofWord + 1);
	if (!words[brofWords])
	{
		deleteMatrix(words, brofWords);
		cout << "not memory enought";
		return;
	}
	myStrcpy(words[brofWords], temp);
}
void randomExpression(char** words,int index)
{
	for (int i = 0; i < index; i++)
	{
		int firstrandomIndex = rand() % index;
		int secondRandomIndex = rand() % index;
		char* temp = words[firstrandomIndex];
		words[firstrandomIndex] = words[secondRandomIndex];
		words[secondRandomIndex] = temp;
	}
}
void print(char** str, int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << str[i] << " ";
	}
}
int main()
{
	srand(time(nullptr));
	char str[MAX_SIZE];
	cin.getline(str, MAX_SIZE);
	// Young student the Force is strong with you!
	char** words = nullptr;
	int index = 0;
	index = lenofWords(str);
	words = createMatrix(index);
	if (!words)
	{
		cout << "not memory enough";
		return 0;
	}
	dymnamicWords(str, words);
	if (!words)
	{
		cout << "not memory enought";
		return 0;
	}
	randomExpression(words, index);
	return 0;
}
