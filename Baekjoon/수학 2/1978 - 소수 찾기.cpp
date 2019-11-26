#include <iostream>
#include <vector>

using namespace std;

int answer(vector<int>& v)
{
	int primeCount = 0;

	for (const auto number : v)
	{
		int noRemainderCount = 0;

		for (int i = 1; i <= number; i++)
		{
			if (number == 1) break;
			else if (number == 2)
			{
				primeCount++;
				break;
			}

			if (number % i == 0) noRemainderCount++;
		}

		if (number == 1) continue;
		else if (number == 2) continue;

		if (noRemainderCount == 2) primeCount++;
	}

	return primeCount;
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> numbers;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
	}

	cout << answer(numbers) << endl;
	return 0;
}
