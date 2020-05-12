#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	stack<int> s;
	int* answer = new int[n];
	memset(answer, -1, sizeof(int) * n);

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && v[i] >= s.top())
		{
			s.pop();
		}
		
		if (s.empty())
		{
			answer[i] = -1;
		}
		else if (v[i] < s.top())
		{
			answer[i] = s.top();
		}

		s.push(v[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";
	delete[] answer;

	return 0;
}
