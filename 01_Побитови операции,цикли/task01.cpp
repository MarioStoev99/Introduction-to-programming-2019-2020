#include <iostream>
using namespace std;

int main()
{
    unsigned int a,b,c;
    cin >> a >> b >> c;
    if(a > 99 && a < 1000 && b > 99 && b < 1000 && c > 99 && c < 1000)
    {
        cout << "ne sa tricifreni";
        return 0;
    }
    if(a > c && a > b && b > c)
        cout << a << " " << b << " " << c;
    else if(a > c && a > b && c > b)
    cout << a << " " << c << " " << b;
    else if(b > c && b > a && a > c)
        cout << b << " " << a << " " << c;
    else if(b > c && b > a && c > a)
        cout << b << " " << c << " " << a;
    else if(c > a && c > b && b > a)
        cout << c << " " << b << " " << a;
    else
        cout << c << " " << a << " " << b;
    return 0;
}
