#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string expression;
	cin >> expression;

	stack<char> s;

	string answer = "";

	// 비슷하게 생각은 했는데 해결 방법에서 막혔다.
	for (int i = 0; i < expression.size(); i++)
	{
		const char c = expression[i];

		if (c >= 'A' && c <= 'Z')
		{
			answer += c;
		}
		else if (c == '+' || c == '-')
		{
			// ( 이외의 모든 연산자에 대해 pop 되어야 한다.
			while (!s.empty() && (s.top() != '('))
			{
				answer += s.top();
				s.pop();
			}

			s.push(c);
		}
		else if (c == '*' || c == '/')
		{
			// * 또는 / 가 있을 때만 pop 되어야 한다.
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
