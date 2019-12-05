#include <iostream>
using namespace std;

int main()
{
    unsigned int number;
    cin >> number;
    if(number > 3000)
    {
        cout << "Invalid number!";
        return 0;
    }
    if(number == 0)
    {
        cout << "Invalid number!";
        return 0;
    }
    switch(number / 1000)
    {
        case 3:cout << "M"; number -= 1000;
        case 2:cout << "M"; number -= 1000;
        case 1:cout << "M"; number -= 1000;
    }
    if(number >= 900 && number < 1000)
    {
        cout << "CM";
        number -= 900;
    }
    else if(number >= 400 && number < 500) // 400 - 500
    {
         cout << "CD";
         number -= 400;
    }
    else if(number >= 500)
    {
        cout << "D";
        number -= 500;
    }
    switch(number / 100)
    {
        case 3: cout << "C"; number -= 100;
        case 2: cout << "C"; number -= 100;
        case 1: cout << "C"; number -= 100;
    }
    if(number >= 90)
    {
        cout << "XC";
        number -= 90;
    }
    else if(number >= 40 && number < 50)
    {
        cout << "XL";
        number -= 40;
    }
    else if(number >= 50)
    {
        cout << "L";
        number -= 50;
    }
    switch(number / 10)
    {
        case 3:cout << "X";
        case 2:cout << "X";
        case 1:cout << "X";
    }
    switch(number % 10)
    {
        case 9:cout << "IX";break;
        case 8:cout << "VIII";break;
        case 7:cout << "VII";break;
        case 6:cout << "VI";break;
        case 5:cout << "V";break;
        case 4:cout << "IV";break;
        case 3:cout << "I";
        case 2:cout << "I";
        case 1:cout << "I";
    }
	return 0;
}
