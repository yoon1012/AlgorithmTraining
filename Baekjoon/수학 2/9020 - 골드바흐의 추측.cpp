#include <iostream>
#include <vector>

using namespace std;

struct Goldbach
{
	int a;
	int b;

	int difference()
	{
		return b - a;
	}
};

vector<int> primeNumbers;

bool isPrimeNumber(int n)
{
	for (int i = 0; i < primeNumbers.size(); i++)
	{
		if (primeNumbers[i] > n)
			break;

		if (primeNumbers[i] == n)
			return true;
	}

	return false;
}

vector<Goldbach> getCombinations(int n)
{
	vector<Goldbach> result;

	for (int i = 0; i < primeNumbers.size(); i++)
	{
		if (primeNumbers[i] >= n)
			break;

		Goldbach g;
		g.a = primeNumbers[i];
		g.b = n - primeNumbers[i];

		if (isPrimeNumber(g.b) && (g.a <= g.b))
		{
			result.push_back(g);
		}
	}

	return result;
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	bool numbers[10001];

	for (int i = 0; i < 10001; i++)
	{
		numbers[i] = true;
	}

	numbers[1] = false;

	for (int i = 2; i < 10001; i++)
	{
		if (numbers[i] == false)
			continue;

		int j = 2;

		while (i * j < 10001)
		{
			numbers[i * j] = false;
			j++;
		}
	}

	for (int i = 2; i < 10001; i++)
	{
		if (numbers[i] == true)
			primeNumbers.push_back(i);
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		vector<Goldbach> combinations = getCombinations(n);
		int minDifference = 10000;
		int minDifferenceIndex = -1;

		for (int i = 0; i < combinations.size(); i++)
		{
			if (minDifference > combinations[i].difference())
			{
				minDifference = combinations[i].difference();
				minDifferenceIndex = i;
			}
		}

		cout << combinations[minDifferenceIndex].a << " " << combinations[minDifferenceIndex].b << "\n";
	}

	return 0;
}
