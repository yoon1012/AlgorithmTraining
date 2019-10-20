#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true)
    {
        if (cin.eof()) break;

        int a, b;
        
        cin >> a >> b;
        cout << a + b << "\n";
    }

    return 0;
}
