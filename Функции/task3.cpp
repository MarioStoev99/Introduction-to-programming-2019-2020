#include <iostream>
using namespace std;
int myPow(int n,int k)
{
    int temp = k;
    while(k != 1)
    {
        k--;
        n *= temp;
    }
    return n;
}
int main()
{
    int n,k;
    cin >> n >> k;
    cout << myPow(n,k);
    return 0;
}
