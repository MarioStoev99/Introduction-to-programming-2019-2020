#include <iostream>
using namespace std;

int main()
{
    // ествествено
    unsigned n;
    //махаме нулата
    do
    {
        cin >> n;
    } while(n == 0);
    // 1 винаги ще участва,защото потребителят трябва да въведе естествено число
    int count = 0;
    // докато каунта не стигне до n принти принти кратните на 2 || 3 || 5 && 1
    for(int i = 1;count != n;i++)
    {
        if(i == 1 || i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
        {
            cout << i << " ";
            count++;
        }
    }
    return 0;
}
