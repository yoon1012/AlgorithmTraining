#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red)
{
	vector<int> answer;

	int total = brown + red;
	
	for (int w = 1 ; w <= total ; w++)
	{
		int h = total / w;

		if (total % w != 0)
			continue;
		
		if (((w - 2) * (h - 2) == red) && ((2 * w) + (2 * h) - 4 == brown))
		{
			if (w < h) continue;

			answer.push_back(w);
			answer.push_back(h);
		}
	}

	return answer;
}
