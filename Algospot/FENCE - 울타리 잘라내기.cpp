#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& h, int left, int right)
{
	if (left == right) return h[left];

	int middle = (left + right) / 2;
	int result = max(solve(h, left, middle), solve(h, middle + 1, right));

	int low = middle;
	int high = middle + 1;
	int height = min(h[low], h[high]);

	result = max(result, height * 2);

	while (left < low || high < right)
	{
		if (high < right && (low == left || h[low - 1] < h[high + 1]))
		{
			++high;
			height = min(height, h[high]);
		}
		else
		{
			--low;
			height = min(height, h[low]);
		}

		result = max(result, height * (high - low + 1));
	}

	return result;
}

int answer()
{
	vector<int> heights;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		heights.push_back(height);
	}

	return solve(heights, 0, heights.size() - 1);
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cout << answer() << endl;
	}

	return 0;
}
