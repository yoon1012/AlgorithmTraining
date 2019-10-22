#include <iostream>
#include <vector>

using namespace std;

long sum(std::vector<int>& a)
{
	long result = 0;

	for (int num : a)
	{
		result += static_cast<long>(num);
	}

	return result;
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> numbers;


	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
	}

	cout << sum(numbers);

	return 0;
}
