#include <iostream>

int main()
{
	unsigned long long int cardNumber;
	std::cout << "vuvedete nomera na kartata : ";
	std::cin >> cardNumber;
	unsigned firstDigit = cardNumber   / 100000000 % 10;
	unsigned thirdDigit = cardNumber   / 1000000 % 10;
	unsigned fourthDigit = cardNumber  / 100000 % 10;
	unsigned fifthDigit = cardNumber   / 10000 % 10;
	unsigned sixthDigit = cardNumber   / 1000 % 10;
	unsigned seventhDigit = cardNumber / 100 % 10;
	unsigned eighthDigit = cardNumber  / 10 % 10;

	if(thirdDigit == 7 || thirdDigit == 9)
    {
        std::cout << "Invalid card number";
        return 0;
    }
	if (firstDigit == 0)
	{
		std::cout << "Invalid card number";
		return 0;
	}
	if (fourthDigit == 0 && fifthDigit == 0   && sixthDigit == 0  &&
       seventhDigit == 0 && eighthDigit == 0)
	{
		std::cout << "Invalid card number";
		return 0;
	}
	std::cout << "{";
    std::cout << "card_version:" << firstDigit << ",";
	switch (thirdDigit)
	{
	case 0:std::cout << "owner_spec:Informatika,"; break;
	case 1:std::cout << "owner_spec:Komputurni nauki,"; break;
	case 2:std::cout << "owner_spec:Informacionni sistemi,"; break;
	case 3:std::cout << "owner_spec:Softuerno injenerstvo,"; break;
	case 4:std::cout << "owner_spec:Prilojna matematika,"; break;
	case 5:std::cout << "owner_spec:Matematika,"; break;
	case 6:std::cout << "owner_spec:Statistika,"; break;
	case 8:std::cout << "owner_spec:Matematika i Informatika,"; break;
	}
	std::cout << "owner_id:" << fourthDigit << fifthDigit << sixthDigit <<
                                seventhDigit << eighthDigit;

	std::cout << "}";
	return 0;
}
