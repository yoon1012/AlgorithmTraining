#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++)
	{
		string line;
		getline(cin, line);
		if (line.empty()) break;

		line += "\n";

		stack<char> word;

		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == ' ' || line[j] == '\n')
			{
				while (!word.empty())
				{
					cout << word.top();
					word.pop();
				}

				cout << line[j];
			}
			else
			{
				word.push(line[j]);
			}
		}
	}

	return 0;
}
