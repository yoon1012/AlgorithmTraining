// 힙
// 05-17-2021

#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int, vector<int>> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    vector<int> data;

    for (string operation : operations)
    {
        istringstream ss(operation);
        string s;
        vector<string> commands;

        while (getline(ss, s, ' '))
        {
            commands.push_back(s);
        }

        int value = stoi(commands[1]);

        if (commands[0] == "I")
        {
            data.push_back(value);
            maxQ.push(value);
            minQ.push(value);
            sort(data.begin(), data.end());
        }
        else if (commands[0] == "D" && !data.empty())
        {
            if (value < 0)
            {
                int min = minQ.top();
                minQ.pop();
                data.erase(data.begin());
            }
            else if (value > 0)
            {
                int max = maxQ.top();
                maxQ.pop();
                data.pop_back();
            }
        }
    }

    if (!data.empty())
    {
        answer.push_back(data[data.size() - 1]);
        answer.push_back(data[0]);
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

#include <iostream>

int main()
{
    auto answer = solution({ "I 7","I 5","I -5","D -1" });
    cout << answer[0] << " " << answer[1] << endl;
    return 0;
}
