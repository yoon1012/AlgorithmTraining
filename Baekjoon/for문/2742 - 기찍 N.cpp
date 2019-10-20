#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++)
    {
        cout << n - i << "\n";
    }

    return 0;
}
