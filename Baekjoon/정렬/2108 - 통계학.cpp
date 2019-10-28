#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> numbers;
	int sum = 0;

	int frequency[8001];
	memset(frequency, 0, sizeof(frequency));

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);

		sum += number;
		frequency[number + 4000] += 1;
	}

	// 이 부분이 문제 D:
	int average = round(double(sum) / n);
	cout << average << endl;

	sort(numbers.begin(), numbers.end());

	int middleIndex = n / 2;
	cout << numbers[middleIndex] << endl;
	
	int maxNumber = 0;
	int maxFrequency = 0;
	bool isSecond = false;

	for (int i = 0; i < 8001; i++)
	{
		int number = i - 4000;

		if (maxFrequency < frequency[i])
		{
			maxNumber = number;
			maxFrequency = frequency[i];
			isSecond = false;
		}
		else if ((maxFrequency == frequency[i]) && !isSecond)
		{
			maxNumber = number;
			isSecond = true;
		}
	}

	cout << maxNumber << endl;
	cout << abs(numbers[numbers.size() - 1] - numbers[0]);

	return 0;
}
