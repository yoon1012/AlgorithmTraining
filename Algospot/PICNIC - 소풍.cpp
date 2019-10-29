#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int countPairs(bool paired[10], bool areFriends[][10], int n)
{
	int firstFree = -1;

	for (int i = 0; i < n; i++)
	{
		if (!paired[i])
		{
			firstFree = i;
			break;
		}
	}

	if (firstFree < 0) return 1;

	int pairs = 0;

	for (int i = firstFree + 1; i < n; i++)
	{
		if (!paired[i] && areFriends[firstFree][i])
		{
			paired[firstFree] = true;
			paired[i] = true;
			pairs += countPairs(paired, areFriends, n);

			// 새로운 경우의 수 찾기
			paired[firstFree] = false;
			paired[i] = false;
		}
	}

	return pairs;
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n, m; // n : 학생 수, m : 친구 쌍의 수
		cin >> n >> m;

		bool areFriends[10][10];
		bool paired[10];

		memset(paired, 0, sizeof(bool) * 10);
		memset(areFriends, 0, sizeof(bool) * 10 * 10);

		for (int j = 0; j < m; j++)
		{
			int f1, f2;
			cin >> f1 >> f2;

			areFriends[f1][f2] = true;
			areFriends[f2][f1] = true;
		}

		cout << countPairs(paired, areFriends, n) << endl;
	}

	return 0;
}
