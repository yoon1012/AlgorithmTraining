#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool compare(Point a, Point b)
{
	if (a.x == b.x)
		return a.y < b.y;

	return a.x < b.x;
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Point> v;

	for (int i = 0; i < n; i++)
	{
		int xi, yi;
		cin >> xi >> yi;

		v.push_back(Point(xi, yi));
	}

	sort(v.begin(), v.end(), compare);

	for (Point p : v)
	{
		cout << p.x << " " << p.y << "\n";
	}

	return 0;
}
