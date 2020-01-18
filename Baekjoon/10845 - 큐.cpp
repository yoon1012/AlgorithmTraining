#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> queue;

	int length = 0;
	int frontIndex = -1;
	int backIndex = -1;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int value;
			cin >> value;

			if (queue.size() <= backIndex + 1)
				queue.push_back(value);
			else
				queue[backIndex + 1] = value;

			if (frontIndex == -1 && backIndex == -1)
			{
				frontIndex = 0;
				backIndex = 0;
			}
			else
			{
				backIndex++;
			}

			length++;
		}
		else if (command == "pop")
		{
			if (length == 0)
			{
				cout << -1 << "\n";
				continue;
			}

			int value = queue[frontIndex];
			cout << value << "\n";

			frontIndex++;
			length--;

			if ((frontIndex == backIndex) && length == 0)
			{
				frontIndex = -1;
				backIndex = -1;
			}
		}
		else if (command == "size")
		{
			cout << length << "\n";
		}
		else if (command == "empty")
		{
			if (length == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command == "front")
		{
			if (length == 0)
				cout << -1 << "\n";
			else
				cout << queue[frontIndex] << "\n";
		}
		else if (command == "back")
		{
			if (length == 0)
				cout << -1 << "\n";
			else
				cout << queue[backIndex] << "\n";
		}
	}

	return 0;
}
