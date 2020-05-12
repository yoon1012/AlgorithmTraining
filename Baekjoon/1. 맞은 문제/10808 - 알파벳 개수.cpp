#include <iostream>

using namespace std;

int occurrence[26];

int main(void)
{
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		const char c = input[i];
		const int index = c - 'a';

		occurrence[index]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << occurrence[i] << " ";
	}

	cout << "\n";
	return 0;
}
