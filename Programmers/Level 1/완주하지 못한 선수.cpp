// 해시
// 01-11-2021

#include <string>
#include <vector>

using namespace std;

#include <set>

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	multiset<string> pSet, cSet;

	for (auto p : participant)
		pSet.insert(p);

	for (auto c : completion)
		cSet.insert(c);

	auto pIt = pSet.begin();

	while (pIt != pSet.end())
	{
		auto searchResult = cSet.find(*pIt);

		if (searchResult != cSet.end())
		{
			pSet.erase(pIt);
			cSet.erase(searchResult);

			// 완주자 multiset이 비어있는 경우
			if (cSet.size() == 0)
				break;
		}

		pIt++;
	}

	answer = *(pSet.begin());
	return answer;
}
