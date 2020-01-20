#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string word;
	int commandCount;
	cin >> word >> commandCount;
	
	stack<char> left, right;
	int cursorLocation = word.size();

	for (char letter : word)
	{
		left.push(letter);
	}

	for (int i = 0; i < commandCount; i++)
	{
		char command;
		cin >> command;

		switch (command)
		{
		case 'P':
		{
			char input;
			cin >> input;

			left.push(input);
			cursorLocation++;

			break;
		}
		case 'L':
		{
			if (cursorLocation > 0)
			{
				char leftTop = left.top();
				left.pop();
				right.push(leftTop);

				cursorLocation--;
			}
			break;
		}
		case 'D':
		{
			if (cursorLocation < left.size() + right.size())
			{
				char rightTop = right.top();
				right.pop();
				left.push(rightTop);

				cursorLocation++;
			}
			break;
		}
		case 'B':
		{
			if (cursorLocation > 0)
			{
				left.pop();
				cursorLocation--;
			}

			break;
		}
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	cout << "\n";
	return 0;
}
