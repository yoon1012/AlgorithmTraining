#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;

    cin >> n >> x;

    for (int i = 0 ; i < n ; i++)
    {
        int a;
        cin >> a;

        if (a < x) cout << a << " ";
    }

    cout << "\n";
    return 0;
}
