#include <iostream>

using namespace std;

int d[1001];

int answer(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;

	if (d[n] > 0) return d[n];

	d[n] = answer(n - 1) + answer(n - 2);
	d[n] %= 10007;

	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << (answer(n) % 10007) << "\n";
	return 0;
}
