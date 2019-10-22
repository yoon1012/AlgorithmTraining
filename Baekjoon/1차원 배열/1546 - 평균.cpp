#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	double* arrD = new double[n];
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		double newScore = (double)arr[i] / max * 100;
		sum += newScore;
	}

	cout << fixed;
	cout.precision(2);

	cout << sum / n << endl;

	delete arr;
	delete arrD;

	return 0;
}
