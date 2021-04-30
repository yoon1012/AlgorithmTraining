// 정렬
// 03-12-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());
    if (citations[0] == 0)
    {
        return answer;
    }

    vector<int> citationCount(citations[0] + 1);
    for (auto c : citations)
        citationCount[c]++;

    for (int hTemp = citations[0]; hTemp >= 0; hTemp--)
    {
        int hCitedSum = 0;

        for (int i = hTemp; i < citations[0] + 1; i++)
        {
            if (citationCount[i] > 0)
            {
                hCitedSum += citationCount[i];
            }
        }

        if ((citations.size() - hCitedSum <= hTemp) && (hTemp <= hCitedSum))
        {
            if (hTemp > answer)
                answer = hTemp;
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution({3, 0, 6, 1, 5});
    cout << answer << endl;
    return 0;
}
