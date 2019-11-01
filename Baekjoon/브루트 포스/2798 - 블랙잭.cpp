#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int>& cards, int maxSum)
{
	int currentSum = -1;

	for (int i = 0; i < cards.size() - 2; i++)
	{
		for (int j = i + 1; j < cards.size() - 1; j++)
		{
			for (int k = j + 1; k < cards.size(); k++)
			{
				int sum = cards[i] + cards[j] + cards[k];

				if (sum > maxSum) continue;
				else if (currentSum < 0)
				{
					currentSum = sum;
					continue;
				}

				if ((maxSum - sum) < abs(maxSum - currentSum))
				{
					currentSum = sum;
				}
			}
		}
	}

	return currentSum;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> cards;

	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		cards.push_back(card);
	}

	cout << solve(cards, m) << endl;
	return 0;
}
