#include <iostream>
using namespace std;

int main()
{
    int num, fnum;
    cout << "program to generate 40 random numbers from a range of x to y\n";
    cout <<  "x: ";
    cin >> fnum;
    cout << "y: ";
    cin >> num;
    cout << endl;

    int range = num - fnum;
    for (int i = 0; i < 40; i++)
    {
        cout << rand() % range + fnum << ", ";
    }

    cout << endl;
    return 0;
}