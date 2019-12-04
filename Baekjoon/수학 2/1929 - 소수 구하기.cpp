#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool numbers[1000001];

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n + 1; i++)
	{
		numbers[i] = true;
	}

	numbers[1] = false;

	for (int i = 2; i < n + 1; i++)
	{
		if (numbers[i] == false)
			continue;

		int j = 2;

		while (i * j < n + 1)
		{
			numbers[i * j] = false;
			j++;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (numbers[i])
		{
			cout << i << "\n";
		}
	}

	return 0;
}
