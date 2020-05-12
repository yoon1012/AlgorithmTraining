#include <iostream>

using namespace std;

int main(void)
{
	bool* numbers = new bool[1000001];

	for (int i = 0; i < 1000001; i++)
	{
		numbers[i] = true;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (i == 1)
		{
			numbers[i] = false;
			continue;
		}
		else if (!numbers[i])
		{
			continue;
		}

		int multiplier = 2;
		while (multiplier * i <= 1000000)
		{
			numbers[multiplier * i] = false;
			multiplier++;
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		if (!numbers[i])
		{
			continue;
		}

		cout << i << "\n";
	}

	return 0;
}
