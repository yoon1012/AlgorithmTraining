#include <iostream>
#include <vector>

using namespace std;

bool exists(char target, const vector<char>& v)
{
	for (int i = 0 ; i < v.size(); i++)
	{
		if (target == v[i]) return true;
	}

	return false;
}

int main(void)
{
	int n;
	cin >> n;

	int groupWordCount = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		vector<char> occurredLetters;
		int occurrence = 0;
		char occurredLetter = s[0];
		bool isGroupWord = true;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == occurredLetter)
			{
				occurrence++;

				if (occurrence == 1)
				{
					if (exists(s[j], occurredLetters))
					{
						isGroupWord = false;
						break;
					}

					occurredLetters.push_back(s[j]);
				}
			}
			else
			{
				occurrence = 1;
				occurredLetter = s[j];

				if (exists(s[j], occurredLetters))
				{
					isGroupWord = false;
					break;
				}

				occurredLetters.push_back(s[j]);
			}
		}

		if (isGroupWord) groupWordCount++;
	}

	cout << groupWordCount << endl;

	return 0;
}
