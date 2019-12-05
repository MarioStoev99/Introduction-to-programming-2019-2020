#include <iostream>
using namespace std;

int main()
{
    unsigned cardNumber;
    enum gender{woman,man};
    enum hair{bright_hair,dark_hair};
    enum eyes{bright_eyes,dark_eyes};
    gender x = man;
    hair y = bright_hair;
    eyes z = bright_eyes;
    cin >> cardNumber;
    unsigned secondDigit = cardNumber / 10000000 % 10;
    unsigned seniorDigit = 0;
    unsigned juniorDigit = 0;
    unsigned midDigit = 0;
    unsigned checkDigit = cardNumber % 10;
    if(secondDigit > 7)
    {
        cout << "Imitative";
        return 0;
    }
    else
    {
        juniorDigit = secondDigit % 2;
        secondDigit /= 2;
        midDigit = secondDigit % 2;
        secondDigit /= 2;
        seniorDigit = secondDigit % 2;
        secondDigit /= 2;
    }
    if(juniorDigit == 1)
    {
        x = man;
    }
    else
    {
        x = woman;
    }
    if(midDigit == 1)
    {
        y = dark_hair;
    }
    else
    {
        y = bright_hair;
    }
    if(seniorDigit == 1)
    {
        z = dark_eyes;
    }
    else
    {
        z = bright_eyes;
    }
    int copyCard = cardNumber;
    int evenPos = 0;
    int oddPos = 0;
    for(int i = 9;i >= 1;i--)
    {
        int remainder;
        if(i % 2 != 0)
        {
            remainder = copyCard % 10;
            oddPos += remainder;
        }
        else
        {
            remainder = copyCard % 10;
            evenPos += remainder;
        }
        copyCard /= 10;
    }
    int sum = oddPos*evenPos;
    if(y == bright_hair && z == bright_eyes)
    {
        sum = sum | 0xBABE;
    }
    else if(y == dark_hair && z == dark_eyes)
    {
        sum = sum | 0xCAFE;
    }
    else
    {
        sum = sum | 0xC001;
    }
    if(x == 0)
    {
        sum = sum ^ 0xFACE;
    }
    else
    {
        sum = sum ^ 0xC0DE;
    }
    unsigned count = 0;
    unsigned sum1 = sum;
    while(sum1)
    {
        count++;
        sum1 >>= 1;
    }
    if(count > 4)
    {
        while(count != 4)
        {
            count--;
            sum >>= 1;
        }
    }
    if(sum >= 10)
    {
        sum = sum % 10;
    }
    if(sum == checkDigit)
        cout << "Authentic";
    else
        cout << "Imitative";
    return 0;
}
