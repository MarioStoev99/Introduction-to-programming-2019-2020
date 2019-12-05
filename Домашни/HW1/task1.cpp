#include <iostream>

int main()
{
	int x1, y1, r1;
	int x2, y2, r2;
	std::cin >> x1 >> y1 >> r1;
	std::cin >> x2 >> y2 >> r2;
	int d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int r = (r1 + r2)*(r1 + r2);
	int private_r = (r1 - r2)*(r1 - r2);
	if(private_r > d)
    {
        std::cout << "okrujnostite nqmat obshti tochki";
    }
	else if (d < r)
	{
		std::cout << "okrujnostite se presichat";
	}
	else if (d == r)
	{
		std::cout << "okrujnostite se dopirat";
	}
	else
        std::cout << "okrujnostite nqmat obshti tochki";
	return 0;
}
