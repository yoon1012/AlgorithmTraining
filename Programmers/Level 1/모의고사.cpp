// 완전탐색
// 03-17-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> guess1 = {1, 2, 3, 4, 5};
    vector<int> guess2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> guess3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int spj[3] = {0, 0, 0};

    for (auto i = 0; i < answers.size(); i++)
    {
        auto guessIndex1 = i % guess1.size();
        auto guessIndex2 = i % guess2.size();
        auto guessIndex3 = i % guess3.size();

        if (answers[i] == guess1[guessIndex1])
        {
            spj[0]++;
        }

        if (answers[i] == guess2[guessIndex2])
        {
            spj[1]++;
        }

        if (answers[i] == guess3[guessIndex3])
        {
            spj[2]++;
        }
    }

    vector<pair<int, int>> spjInfo;

    for (auto i = 0; i < 3; i++)
    {
        spjInfo.push_back(make_pair(i + 1, spj[i]));
    }

    sort(spjInfo.begin(), spjInfo.end(), compare);
    int maxScore = spjInfo[0].second;

    for (auto i = 0; i < spjInfo.size(); i++)
    {
        if (spjInfo[i].second < maxScore)
        {
            break;
        }

        answer.push_back(spjInfo[i].first);
    }

    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution({1, 3, 2, 4, 2});
    for (auto a : answer)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}
