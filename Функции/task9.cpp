#include <iostream>
using namespace std;
void print(int max)
{
    cout << max;
}
int input(int n,int max = -999)
{
    int number;
    for(int i = 0;i < n;i++)
    {
        cin >> number;
        if(number > max)
            max = number;
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    //input(n);
    print(input(n));
    return 0;
}
