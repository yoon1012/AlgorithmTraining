#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> dq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;

		if (command == "push_front")
		{
			int value;
			cin >> value;
			dq.push_front(value);
		}
		else if (command == "push_back")
		{
			int value;
			cin >> value;
			dq.push_back(value);
		}
		else if (command == "pop_front")
		{
			if (dq.size() == 0)
			{
				cout << -1 << "\n";
				continue;
			}

			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (command == "pop_back")
		{
			if (dq.size() == 0)
			{
				cout << -1 << "\n";
				continue;
			}

			cout << dq.back() << "\n";
			dq.pop_back();
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "empty")
		{
			if (dq.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command == "front")
		{
			if (dq.size() == 0)
				cout << -1 << "\n";
			else
				cout << dq.front() << "\n";
		}
		else if (command == "back")
		{
			if (dq.size() == 0)
				cout << -1 << "\n";
			else
				cout << dq.back() << "\n";
		}
	}

	return 0;
}
