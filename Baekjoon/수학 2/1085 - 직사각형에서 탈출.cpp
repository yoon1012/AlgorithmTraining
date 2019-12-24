#include <iostream>

using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int minWidth, minHeight;

	if (x < w - x)
		minWidth = x;
	else
		minWidth = w - x;

	if (y < h - y)
		minHeight = y;
	else
		minHeight = h - y;

	if (minWidth < minHeight)
		cout << minWidth;
	else
		cout << minHeight;

	return 0;
}
