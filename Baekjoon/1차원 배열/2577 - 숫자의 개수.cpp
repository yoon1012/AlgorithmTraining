#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int a, b, c;

	cin >> a >> b >> c;

	int result = a * b * c;
	string resultString = to_string(result);

	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	for (int i = 0; i < resultString.length(); i++)
	{
		int value = resultString[i] - '0';
		count[value]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}
