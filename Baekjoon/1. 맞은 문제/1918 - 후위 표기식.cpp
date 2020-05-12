#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string expression;
	cin >> expression;

	stack<char> s;

	string answer = "";

	for (int i = 0; i < expression.size(); i++)
	{
		const char c = expression[i];

		if (c >= 'A' && c <= 'Z')
		{
			answer += c;
		}
		else if (c == '+' || c == '-')
		{
			// ( 를 제외한 모든 연산자를 만나면 pop 되어야 한다.
			while (!s.empty() && (s.top() != '('))
			{
				answer += s.top();
				s.pop();
			}

			s.push(c);
		}
		else if (c == '*' || c == '/')
		{
			// * 또는 / 를 만나면 pop 되어야 한다.
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				answer += s.top();
				s.pop();
			}

			s.push(c);
		}
		else if (c == '(')
		{
			s.push(c);
		}
		else if (c == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				answer += s.top();
				s.pop();
			}

			s.pop();
		}
	}

	while (!s.empty())
	{
		answer += s.top();
		s.pop();
	}

	cout << answer << "\n";
	return 0;
}
