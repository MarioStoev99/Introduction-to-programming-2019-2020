#include <iostream>
using namespace std;

int main()
{
    int data = 500;
    cout << (data >> 8) << endl;;
    data = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff);
    cout << data << endl;
    return 0;
    // 1 0010 0011 0100‬
    //11 0100 0001 0010
}
