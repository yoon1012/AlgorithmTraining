#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	stack<char> s;
	int count = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (((i + 1) < input.size()) && input[i] == '(' && input[i + 1] == ')')
		{
			count += s.size();
		}
		else if (((i - 1) > -1) && input[i - 1] == '(' && input[i] == ')')
		{
			continue;
		}
		else if (input[i] == '(')
		{
			s.push(input[i]);
		}
		else if (input[i] == ')')
		{
			count++;
			s.pop();
		}
	}

	cout << count << "\n";
	return 0;
}
