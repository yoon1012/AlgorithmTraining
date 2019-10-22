#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> arr[i];
	}

	int min = arr[0], max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}

		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	cout << min << " " << max << endl;

	delete arr;
	return 0;
}
