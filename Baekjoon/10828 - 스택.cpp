#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;
int top = -1;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 명령어에 따라 숫자를 추가로 입력받게 한다.
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int value;
			cin >> value;

			if (stack.size() <= top + 1)
				stack.push_back(value);
			else
				stack[top + 1] = value;

			top++;
		}
		else if (command == "pop")
		{
			if (top < 0)
				cout << -1 << "\n";
			else
				cout << stack[top--] << "\n";
		}
		else if (command == "size")
		{
			cout << top + 1 << "\n";
		}
		else if (command == "empty")
		{
			if (top < 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command == "top")
		{
			if (top < 0)
				cout << -1 << "\n";
			else
				cout << stack[top] << "\n";
		}
	}

	return 0;
}
