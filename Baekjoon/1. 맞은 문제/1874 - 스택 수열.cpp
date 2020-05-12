#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		v.push_back(input);
	}

	int current = 1;
	bool isValid = true;
	int numsToGo = v.size();

	stack<int> s;
	string answer = "";

	while (isValid && numsToGo > 0)
	{
		const int goalIndex = v.size() - numsToGo;
		const int goalValue = v[goalIndex];

		if (current < goalValue)
		{
			s.push(current++);
			answer += "+\n";
		}
		else if (goalValue < current)
		{
			// 스택이 빈 경우도 처리해야 한다.
			if (s.empty() || s.top() < goalValue)
			{
				answer = "NO\n";
				isValid = false;
				continue;
			}

			int top = s.top();

			s.pop();
			answer += "-\n";

			if (top == goalValue)
			{
				numsToGo--;
			}
		}
		else if (current == goalValue)
		{
			s.push(current++);
			answer += "+\n";

			s.pop();
			answer += "-\n";

			numsToGo--;
		}
	}

	cout << answer << "\n";
	return 0;
}
