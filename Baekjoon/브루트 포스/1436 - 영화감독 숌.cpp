#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int number = 0;
	int count = 0;

	while (count < n)
	{
		string numberString = to_string(number);
		if (numberString.find("666") != string::npos)
		{
			count++;
		}

		if (count == n) break;

		number++;
	}

	cout << number << endl;
	return 0;
}
