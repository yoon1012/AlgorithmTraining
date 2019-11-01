#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User
{
	int id;
	int age;
	string name;

	User(int id, int age, string name)
	{
		this->id = id;
		this->age = age;
		this->name = name;
	}
};

bool compare(User u1, User u2)
{
	if (u1.age == u2.age)
	{
		return u1.id < u2.id;
	}

	return u1.age < u2.age;
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int count = 0;
	vector<User> users;

	for (int i = 0; i < n; i++)
	{
		int age;
		string name;

		cin >> age >> name;
		users.push_back(User(count++, age, name));
	}

	sort(users.begin(), users.end(), compare);

	for (User u : users)
	{
		cout << u.age << " " << u.name << "\n";
	}

	return 0;
}
