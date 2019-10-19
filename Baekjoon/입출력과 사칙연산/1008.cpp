#include <iostream>

using namespace std;

int main(void)
{
    int a, b;

    cin >> a >> b;
    cout.precision(12); // 이 부분이 핵심
    cout << static_cast<double>(a) / b << endl;

    return 0;
}
