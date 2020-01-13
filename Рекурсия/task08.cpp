#include <iostream>
using namespace std;
int gcd(int n,int m)
{
    if(n == 0)
        return 0;
    if(m == 0)
        return 0;
    if(n == m)
        return n;
    if(n > m)
        return gcd(n - m,m);
    else
        return gcd(n,m - n);
}
int main()
{
    cout << gcd(132,11);
    return 0;
}
