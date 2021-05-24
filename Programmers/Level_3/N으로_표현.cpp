// 동적계획법
// 05-21-2021

#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int solution(int N, int number)
{
    int answer = 0;

    if (N == number)
    {
        answer = 1;
        return answer;
    }

    vector<unordered_set<int>> d;

    for (int i = 0; i < 8; i++)
    {
        unordered_set<int> di;

        if (i == 0)
        {
            di.insert(N);
        }
        else
        {
            di.insert(N * pow(10, i) + *d[i - 1].begin());
        }

        d.push_back(di);
    }

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto a = d[j].begin(); a != d[j].end(); a++)
            {
                for (auto b = d[i - j - 1].begin(); b != d[i - j - 1].end(); b++)
                {
                    d[i].insert(*a + *b);
                    d[i].insert(*a * *b);
                    d[i].insert(*a - *b);

                    if (*b != 0)
                    {
                        d[i].insert(*a / *b);
                    }
                }
            }
        }

        if (d[i].count(number) > 0)
        {
            answer = i + 1;
            break;
        }
    }

    if (answer == 0 || answer > 8)
    {
        answer = -1;
    }

    return answer;
}

#include <iostream>

int main()
{
    auto answer = solution(5, 12);
    cout << answer << endl;
    return 0;
}
