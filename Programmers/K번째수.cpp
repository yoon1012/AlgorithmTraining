// 정렬
// Level 1
// 03-10-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (auto command : commands)
    {
        auto i = command[0] - 1;
        auto j = command[1] - 1;
        auto k = command[2] - 1;

        vector<int> arrayCopy(j - i + 1);
        copy(array.begin() + i, array.begin() + j + 1, arrayCopy.begin());
        sort(arrayCopy.begin(), arrayCopy.end());

        answer.push_back(arrayCopy[k]);
    }

    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} });

    for (auto a : answer)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}
