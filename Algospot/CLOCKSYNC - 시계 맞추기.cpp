#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> clockStates;

string connections[10] =
{
	"1110000000000000",
	"0001000101010000",
	"0000100000100011",
	"1000111100000000",
	"0000001110101000",
	"1010000000000011",
	"0001000000000011",
	"0000110100000011",
	"0111110000000000",
	"0001110001000100"
};

int move(int switchCount[], const vector<int>& clockState)
{
	vector<int> clockStateCopy;

	for (int i = 0; i < 16; i++)
	{
		clockStateCopy.push_back(clockState[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		if (switchCount[i] == 0) continue;

		string connection = connections[i];

		for (int j = 0; j < 16; j++)
		{
			if (connection[j] == '1')
			{
				clockStateCopy[j] += 3 * switchCount[i];
				if (clockStateCopy[j] > 12) clockStateCopy[j] -= 12;
			}
		}
	}

	int twelveCount = 0;

	for (int i = 0; i < 16; i++)
	{
		if (clockStateCopy[i] == 12)
		{
			twelveCount++;
		}
	}

	if (twelveCount < 16) return -1;

	int switchSum = 0;

	for (int i = 0; i < 10; i++)
	{
		switchSum += switchCount[i];
	}

	return switchSum;
}

int solve(const vector<int>& clockState)
{
	int answer = -1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					for (int m = 0; m < 4; m++)
					{
						for (int n = 0; n < 4; n++)
						{
							for (int o = 0; o < 4; o++)
							{
								for (int p = 0; p < 4; p++)
								{
									for (int q = 0; q < 4; q++)
									{
										for (int r = 0; r < 4; r++)
										{
											int switchCount[10] = { i, j, k, l, m, n, o, p, q, r };
											int result = move(switchCount, clockState);

											if (result < 0) continue;
											else if (result == 0) return 0;

											if (answer < 0) answer = result;
											else if (answer > result) answer = result;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return answer;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> clockState;

		for (int j = 0; j < 16; j++)
		{
			int time;
			cin >> time;
			clockState.push_back(time);
		}

		clockStates.push_back(clockState);
	}

	for (int i = 0; i < clockStates.size(); i++)
	{
		cout << solve(clockStates[i]) << endl;
	}

	return 0;
}
