#include <iostream>
#include <vector>

using namespace std;

struct User
{
	int weight;
	int height;
};

int getRank(int index, const vector<User>& users)
{
	int rank = 1;

	for (int i = 0; i < users.size(); i++)
	{
		if (i == index) continue;

		if ((users[i].height > users[index].height) &&
			(users[i].weight > users[index].weight))
		{
			rank++;
		}
	}

	return rank;
}

int main(void)
{
	int n;
	cin >> n;

	vector<User> users;

	for (int i = 0; i < n; i++)
	{
		User u;
		cin >> u.weight >> u.height;

		users.push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		cout << getRank(i, users) << " ";
	}

	cout << "\n";
	return 0;
}
