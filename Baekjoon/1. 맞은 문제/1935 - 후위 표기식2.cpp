#pragma warning(disable: 4996)

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	char expression[101];
	scanf("%s", expression);

	stack<double> s;
	int* numbers = new int[n];

	for (int i = 0; i < n; i++)
	{
		int number;
		scanf("%d", &number);
		numbers[i] = number;
	}

	for (int i = 0; i < strlen(expression); i++)
	{
		const char c = expression[i];

		if (c >= 'A' && c <= 'Z')
		{
			s.push(numbers[c - 'A']);
		}
		else if (c == '*')
		{
			double v2 = s.top();
			s.pop();
			double v1 = s.top();
			s.pop();

			s.push(v1 * v2);
		}
		else if (c == '+')
		{
			double v2 = s.top();
			s.pop();
			double v1 = s.top();
			s.pop();

			s.push(v1 + v2);
		}
		else if (c == '/')
		{
			double v2 = s.top();
			s.pop();
			double v1 = s.top();
			s.pop();

			s.push((double)v1 / v2);
		}
		else if (c == '-')
		{
			double v2 = s.top();
			s.pop();
			double v1 = s.top();
			s.pop();

			s.push(v1 - v2);
		}
	}

	printf("%.2lf\n", s.top());

	delete[] numbers;
	return 0;
}
