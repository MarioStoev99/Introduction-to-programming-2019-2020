#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x1 - x2;
    int b = y1 - y2;
    float c = sqrt(a*a + b*b) / 1.;
    cout << "distance : " << c;
    return 0;
}
