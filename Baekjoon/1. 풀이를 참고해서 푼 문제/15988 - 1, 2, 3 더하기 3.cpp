#include <iostream>

using namespace std;

long long mod = 1000000009;
long long d[1000001] = { 0, 1, 2, 4 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 4; i < 1000001; i++)
	{
		d[i] = (long long)(d[i - 1] + d[i - 2] + d[i - 3]) % mod;
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}

	return 0;
}
