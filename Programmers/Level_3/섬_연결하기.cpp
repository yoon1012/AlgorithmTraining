// 탐욕법
// 05-03-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parentNode[100];

int compare(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int getStartNode(int i)
{
    if (i == parentNode[i]) return i;
    return parentNode[i] = getStartNode(parentNode[i]);
}

bool hasSameStartNode(int i, int j)
{
    if (getStartNode(i) == getStartNode(j))
        return true;

    return false;
}

void connect(int i, int j)
{
    parentNode[i] = j;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);

    for (int i = 0; i < n; i++)
    {
        parentNode[i] = i;
    }

    // 연결하는 부분에서 막힘
    for (auto cost : costs)
    {
        if (hasSameStartNode(cost[0], cost[1]))
            continue;

        auto start = getStartNode(cost[0]);
        auto end = getStartNode(cost[1]);

        answer += cost[2];
        parentNode[start] = end;
    }

    return answer;
}

#include <iostream>

int main()
{
    int n = 4;
    vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

    auto answer = solution(n, costs);
    cout << answer << endl;
    return 0;
}
