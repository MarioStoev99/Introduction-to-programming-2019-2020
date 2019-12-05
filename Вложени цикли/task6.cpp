#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout << "vuvedete broq na kolonite : ";
    cin >> y;
    cout << "vuvedete broq na redovete : ";
    cin >> x;
    for(int i = 0;i < x;i++)
    {
        for(int j = 0;j < y;j++)
        {
            if(i == 0 || i == x - 1 || j == 0 || j == y - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
