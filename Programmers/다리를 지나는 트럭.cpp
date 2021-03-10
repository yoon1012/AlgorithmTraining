// 스택/큐
// Level 2
// 03-08-2021

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    queue<int> left, right;
    vector<pair<int, int>> bridge; // 무게, 경과 시간 pair

    for (auto truckWeight : truck_weights)
    {
        right.push(truckWeight);
    }

    while (left.size() < truck_weights.size())
    {
        for (auto& truck : bridge)
        {
            truck.second--;
        }

        if (bridge.size() > 0 && bridge[0].second == 0)
        {
            int truck = bridge[0].first;
            bridge.erase(bridge.begin(), bridge.begin() + 1);

            left.push(truck);
        }

        int weightSum = 0;

        for (auto& truck : bridge)
        {
            weightSum += truck.first;
        }

        if (right.size() > 0)
        {
            int newTruck = right.front();

            if (bridge.size() == 0 || weightSum + newTruck <= weight && !right.empty())
            {
                int newTruck = right.front();
                right.pop();
                bridge.push_back(make_pair(newTruck, bridge_length));
            }
        }

        answer++;
    }

    return answer;
}

#include <iostream>

int main()
{
    auto answer = solution(2, 10, { 7, 4, 5, 6 });
    cout << answer << endl;
    return 0;
}
