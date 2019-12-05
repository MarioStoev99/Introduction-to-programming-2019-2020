#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a + b <= c || a + c <= b || b + c <= a)
        cout << "nqmame takuv triugulnik";
    else
        cout << "imame takuv triugulnik";
    return 0;
}
