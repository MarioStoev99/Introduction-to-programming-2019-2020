#include <iostream>
using namespace std;
void print(int num,int i = 10)
{
    if(num == 0)
        return;
    cout << i << " ";
    print(num - 1,i*10);
    cout << i << " ";
}
int main()
{
    int num;
    cin >> num;
    print(num);
    return 0;
}
