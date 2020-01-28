#include <iostream>
#include <cstring>

using namespace std;

int* d;
int* p;

int answer(int n)
{
    if (n == 0) return 0;
	if (n == 1) return p[1];
	if (d[n] > 0) return d[n];

	int maxSum = 0;

	for (int i = 1; i <= n; i++)
	{
		int lastIndex = n - i;
		if (lastIndex < 0) break;

		int sum = answer(lastIndex) + p[i];

		if (maxSum < sum)
		{
			maxSum = sum;
		}
	}

	d[n] = maxSum;

	return d[n];
} 

int main(void)
{
	int n;
	cin >> n;

	d = new int[n + 1];
	p = new int[n + 1];

	memset(d, 0, sizeof(int) * (n + 1));
	memset(p, 0, sizeof(int) * (n + 1));

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	cout << answer(n) << "\n";

	delete[] d;
	delete[] p;

	return 0;
}
