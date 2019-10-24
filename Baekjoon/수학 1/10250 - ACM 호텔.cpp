#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int row = n % h;
		int column = n / h + 1;

		if (row == 0)
		{
			row = h;
			column = n / h;
		}

		string room = to_string(row);

		if (column < 10)
		{
			room += "0";
		}

		room += to_string(column);
		cout << room << endl;
	}
}
