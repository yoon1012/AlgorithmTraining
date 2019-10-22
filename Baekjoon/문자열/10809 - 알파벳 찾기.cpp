#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int first[26];

	for (int i = 0; i < 26; i++)
	{
		first[i] = -1;
	}

	for (int i = 0; i < s.length(); i++)
	{
		char letter = s[i];
		int index = s[i] - 'a';

		for (int j = 0; j < 26; j++)
		{
			if (first[index] < 0)
			{
				first[index] = i;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << first[i] << " ";
	}

	cout << "\n";

	return 0;
}
