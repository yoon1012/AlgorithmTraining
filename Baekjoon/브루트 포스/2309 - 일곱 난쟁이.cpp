#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heights;

int getTotalWithoutTwoIndices(int index1, int index2)
{
	int sum = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		if (i == index1 || i == index2) continue;

		sum += heights[i];
	}

	return sum;
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		int height;
		cin >> height;
		heights.push_back(height);
	}

	sort(heights.begin(), heights.end());

	int fakeIndex1 = -1;
	int fakeIndex2 = -1;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			int total = getTotalWithoutTwoIndices(i, j);

			if (total == 100)
			{
				fakeIndex1 = i;
				fakeIndex2 = j;

				i = 8;
				j = 9;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == fakeIndex1 || i == fakeIndex2) continue;
		cout << heights[i] << endl;
	}

	return 0;
}
