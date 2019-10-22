#include <iostream>

using namespace std;

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;

		int* scores = new int[n];
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> scores[j];
			sum += scores[j];
		}

		double average = static_cast<double>(sum) / n;
		int overAverageN = 0;

		for (int j = 0; j < n; j++)
		{
			double score = scores[j];
			
			if (score > average)
			{
				overAverageN++;
			}
		}

		cout << fixed;
		cout.precision(3);

		cout << (static_cast<double>(overAverageN) / n) * 100
			 << "%" << endl;

		delete scores;
	}

	return 0;
}
