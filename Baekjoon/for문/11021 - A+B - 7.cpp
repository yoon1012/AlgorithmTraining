#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 1 ; i <= t ; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i << ": " << a + b << "\n";
    }

    return 0;
}
