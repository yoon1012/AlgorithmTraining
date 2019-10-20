#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    int a, b;
    int* result = new int[n];

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a >> b;
        result[i-1] = a + b;
    }

    for (int i = 0 ; i < n ; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}
