#include <iostream>

using namespace std;

int main(void)
{
	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	int maxIndex = 0;

	for (int i = 0; i < 9; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}

	cout << arr[maxIndex] << endl;
	cout << maxIndex + 1 << endl;
}
