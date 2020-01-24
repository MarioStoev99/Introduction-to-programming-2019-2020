#include <iostream>
using namespace std;
void profesorX(int number)
{
	if (number > 0)
	{
		profesorX(number - 1);
		cout << number;
		profesorX(number - 1);
	}
}

int main()
{
	unsigned number;
	do
	{
		cin >> number;
	} while (number == 0 || number > 20);
	profesorX(number);
	return 0;
}
