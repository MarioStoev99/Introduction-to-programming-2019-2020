#include <iostream>
using namespace std;

int main()
{
    unsigned number;
    cin >> number;
    int remainder = number % 13;
    int clr = number / 13;
    switch (clr) {
        case 0:cout << "clubs";break;
        case 1:cout << "diamonds";break;
        case 2:cout << "hearts";break;
        case 3:cout << "SPADES";break;

    }
    switch(remainder)
    {
        case 0:cout << "A ";break;
        case 10:cout << "J";break;
        case 11:cout << "Q";break;
        case 12:cout << "K";break;
        default: cout << (char)(number + 1 + '0');
    }
    return 0;
}
