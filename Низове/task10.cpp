#include <iostream>
using namespace std;
const size_t MAX_SIZE = 1024;
bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}
void crushExpresion(char* words[], char str[],int& index)
{
	words[0] = str;
	bool searchingLetter = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isLetter(str[i]))
		{
			if (searchingLetter)
			{
				words[index++] = str + i;
				searchingLetter = false;
			}
		}
		else
		{
			str[i] = '\0';
			searchingLetter = true;
		}
	}
}
void print(char* words[],int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << words[i] << endl;
	}
}
int myStrcmp(const char* str, const char* str1)
{
	int i;
	for (i = 0; str[i] != '\0' && str[i] == str1[i]; i++)
		;
	return (int)(str[i] - str1[i]);
}
int findEquals(char* words[], const char* dictionary[], int index, int sizeofDictionary)
{
	int count = 0;
	for (int i = 0; i < sizeofDictionary; i++)
	{
		for (int j = 0; j < index; j++)
		{
			if (myStrcmp(dictionary[i], words[j]) == 0)
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	const char* dictionary[] = { "cats","dogs" };
	int sizeofDictionary = 2;
	char str[MAX_SIZE];
	int index = 1;
	cin.getline(str, MAX_SIZE);
	char* words[MAX_SIZE / 2];
	crushExpresion(words, str,index);
	print(words,index);
	cout << findEquals(words, dictionary, index, sizeofDictionary);
	return 0;
}
