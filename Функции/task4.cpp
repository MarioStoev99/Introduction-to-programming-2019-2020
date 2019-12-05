#include <iostream>
using namespace std;
int myAbs(int number)
{
    if(number < 0)
        return -(number);
    return number;
}
int gcd(int number1,int number2)
{
        int nod = 0;
        if(number1 > number2)
            nod = number2;
                if(number2 < 0)
                    nod = myAbs(number2);
        else
            nod = number1;
                if(number1 < 0)
                    nod = myAbs(number1);
        while(nod)
        {
            if(number1 % nod == 0 && number2 % nod == 0)
                return nod;
            else
                nod--;
        }
}
int main()
{
    int number1,number2;
    cin >> number1 >> number2;
    cout << gcd(number1,number2);
    return 0;
}
