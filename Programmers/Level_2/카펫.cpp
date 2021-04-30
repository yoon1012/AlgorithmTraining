// 완전탐색
// 03-22-2021

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (auto h = 1; h <= (yellow / h); h++)
    {
        if (yellow % h != 0)
            continue;

        auto w = yellow / h;
        if (2 * w + 2 * h + 4 + w * h == brown + yellow)
        {
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution(8, 1);
    cout << answer[0] << " " << answer[1] << endl;
    return 0;
}
