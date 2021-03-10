// 스택/큐
// Level 2
// 03-10-2021

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    
    for (auto i = 0; i < prices.size(); i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
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
