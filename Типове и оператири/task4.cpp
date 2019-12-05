#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= 0 || b <= 0 || c <= 0)
    {
        cout << "otricatelni stoinosti";
        return 0;
    }
    int p = ((a + b + c) / 2);
    cout << "S = " << sqrt(p(p - a)*(p - b)*(p - c));
    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    int a,ha;
    int S;
    cin >> a >> ha;
    if(a <= 0 && ha <= 0)
    {
        cout << "greshni danni";
        return 0;
    }
    else
    {
        S = a*ha / 2;
    }
    cout << "liceto na triugulnika e : " << S;
    return 0;
}
*/
