#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (auto i = 0; i < prices.size(); i++)
    {
        if (i == prices.size() - 1)
        {
            answer.push_back(0);
            continue;
        }

        stack<int> futurePrices;

        for (auto j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] >= prices[i])
                futurePrices.push(prices[j]);
            else // 1초 후에 가격이 떨어진다는 것에 주의
            {
                futurePrices.push(prices[j]);
                break;
            }
        }

        answer.push_back(futurePrices.size());
    }

    return answer;
}

#include <iostream>

int main(void)
{
    auto answers = solution({ 1, 2, 3, 2, 3 });

    for (auto answer : answers)
    {
        cout << answer << " ";
    }

    cout << endl;
    return 0;
}
