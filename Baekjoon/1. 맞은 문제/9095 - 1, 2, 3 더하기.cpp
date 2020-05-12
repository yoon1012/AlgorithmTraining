#include <iostream>

using namespace std;

int d[11];

int answer(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (d[n] > 0) return d[n];

	d[n] = answer(n - 1) + answer(n - 2) + answer(n - 3);
	return d[n];
} 

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << answer(n) << "\n";
	}

	return 0;
}
