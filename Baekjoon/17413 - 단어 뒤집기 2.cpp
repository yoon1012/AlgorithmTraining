#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input);
	input += "\n";

	stack<char> letter;
	bool shouldPushStack = true;

	for (char c : input)
	{
		if (c == '<')
		{
			while (!letter.empty())
			{
				cout << letter.top();
				letter.pop();
			}

			shouldPushStack = false;
			cout << c;
		}
		else if (c == '>')
		{
			shouldPushStack = true;
			cout << c;
		}
		else if (!shouldPushStack)
		{
			cout << c;
		}
		else if (c == ' ' || c == '\n')
		{
			while (!letter.empty())
			{
				cout << letter.top();
				letter.pop();
			}

			cout << c;
		}
		else
		{
			letter.push(c);
		}
	}

	return 0;
}
