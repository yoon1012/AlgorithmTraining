#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double average(int* arr, int start, int end)
{
	int count = end + 1 - start;
	int sum = 0;

	for (int i = start; i < end + 1; i++) sum += arr[i];
	return static_cast<double>(sum) / count;
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, l;
		cin >> n >> l;

		int* arr = new int[n];

		for (int j = 0; j < n; j++) cin >> arr[j];

		vector<double> avgs;

		for (int j = l; j <= n; j++)
		{
			for (int k = 0; k < n - j + 1; k++)
			{
				double avg = average(arr, k, k + j - 1);
				avgs.push_back(avg);
			}
		}

		sort(avgs.begin(), avgs.end());
		cout.precision(10);
		cout << fixed << avgs[0] << endl;

		delete arr;
	}

	return 0;
}
