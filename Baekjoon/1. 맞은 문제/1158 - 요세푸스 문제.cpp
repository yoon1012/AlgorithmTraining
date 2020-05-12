#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	cout << "<";

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			int front = q.front();
			q.pop();
			q.push(front);
		}

		int front = q.front();
		q.pop();

		cout << front << ", ";
	}

	if (!q.empty())
	{
		cout << q.front() << ">\n";
	}

	return 0;
}
