#include <iostream>

using namespace std;

int d[1001];

int answer(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (d[n] > 0) return d[n];

	d[n] = answer(n - 2) + answer(n - 1);
	d[n] %= 10007;

	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << answer(n) << "\n";
	return 0;
}
