// 탐욕법
// 05-03-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    int lastCameraPos = routes[0][1];
    answer++;

    for (int i = 0; i < routes.size(); i++)
    {
        if (lastCameraPos < routes[i][0])
        {
            answer++;
            lastCameraPos = routes[i][1];
        }
        else if (routes[i][1] < lastCameraPos)
        {
            lastCameraPos = routes[i][1];
        }
    }
    
    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({ {-20, 15}, { -14, -5 }, { -18, -13 }, { -5, -3 } }) << endl;
    return 0;
}
