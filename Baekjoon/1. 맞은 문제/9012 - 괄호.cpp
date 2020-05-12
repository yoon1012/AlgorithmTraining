#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string line;
		cin >> line;

		bool isValid = true;
		stack<char> parenthesis;

		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == '(')
			{
				parenthesis.push(line[j]);
			}
			else if (line[j] == ')')
			{
				if (parenthesis.empty())
				{
					isValid = false;
					break;
				}
				else if (parenthesis.top() != '(')
				{
					isValid = false;
					break;
				}

				parenthesis.pop();
			}
		}

		if (!parenthesis.empty() || !isValid)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}

	return 0;
}
