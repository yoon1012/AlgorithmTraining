#include <iostream>

using namespace std;

int main(void)
{
    int a, b;

    cin >> a >> b;

    int b1 = b % 10;
    int b2 = (b - b1) % 100;
    int b3 = b - b1 - b2;

    cout << a * b1 << endl;
    cout << (a * b2) / 10 << endl;
    cout << (a * b3) / 100 << endl;
    cout << a * b << endl;

    return 0;
}
