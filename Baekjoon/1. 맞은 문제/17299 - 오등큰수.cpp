#include <iostream>
#include <cstring>
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
	int* occurrence = new int[1000001];
	memset(occurrence, 0, sizeof(int) * 1000001);

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		v.push_back(input);
		occurrence[input]++;
	}

	stack<int> s;
	vector<int> answer(v.size(), -1);
	
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && occurrence[v[s.top()]] <= occurrence[v[i]])
		{
			s.pop();
		}

		if (s.empty())
		{
			answer[i] = -1;
		}
		else
		{
			answer[i] = v[s.top()];
		}

		s.push(i);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];

		if (i < answer.size() - 1)
			cout << " ";
		else
			cout << "\n";
	}

	delete[] occurrence;
	return 0;
}
