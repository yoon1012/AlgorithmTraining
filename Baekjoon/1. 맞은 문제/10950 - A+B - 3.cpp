#include <iostream>

using namespace std;

int solution(int a, int b)
{
	return a + b;
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
        
		cout << solution(a, b) << "\n";
	}

	return 0;
}
