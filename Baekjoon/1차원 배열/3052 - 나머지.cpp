#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	vector<int> remainders;

	for (int i = 0; i < 10; i++)
	{
		int remainder = arr[i] % 42;
		bool exists = false;

		for (int j = 0; j < remainders.size(); j++)
		{
			if (remainder == remainders[j])
			{
				exists = true;
			}
		}

		if (!exists)
		{
			remainders.push_back(remainder);
		}
	}

	cout << remainders.size() << endl;
	return 0;
}
