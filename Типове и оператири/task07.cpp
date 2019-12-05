#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c,x;
    cin >> a >> b >> c;
    int y = a*x*x + b*x + c;
    int D = b*b - 4*a*c;
    int x1 = (- b + sqrt(D)) / (2 * a);
    int x2 = (- b - sqrt(D)) / (2 * a);
    cout << x1 << " " << x2;
    return 0;
}
