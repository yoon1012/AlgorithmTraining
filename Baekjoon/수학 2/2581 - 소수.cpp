#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrimeNumber(int n)
{
	int remainderCount = 0;

	if (n == 1) return false;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			remainderCount++;

			if (remainderCount > 2)
				return false;
		}
	}

	if (remainderCount == 2)
		return true;

	return false;
}

int main(void)
{
	int m, n;
	cin >> m >> n;

	vector<int> primeNumbers;

	for (int i = m; i <= n; i++)
	{
		if (isPrimeNumber(i))
		{
			primeNumbers.push_back(i);
		}
	}

	if (primeNumbers.size() == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	sort(primeNumbers.begin(), primeNumbers.end());

	int sum = 0;

	for (int i = 0; i < primeNumbers.size(); i++)
	{
		sum += primeNumbers[i];
	}

	cout << sum << " " << primeNumbers[0] << endl;

	return 0;
}
