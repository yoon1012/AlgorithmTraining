// 탐욕법
// 03-29-2021

#include <string>
#include <vector>

using namespace std;

int getLeftTarget(int start, string s)
{
    int c = start - 1;
    int result = -1;

    while (c != start)
    {
        if (c < 0)
            c += s.size();

        if (s[c] != 'A')
        {
            result = c;
            break;
        }

        if (c == start)
            break;

        c--;
    }

    return result;
}

int getRightTarget(int start, string s)
{
    int c = start + 1;
    int result = -1;

    while (c != start)
    {
        if (c >= s.size())
            c -= s.size();

        if (s[c] != 'A')
        {
            result = c;
            break;
        }

        if (c == start)
            break;

        c++;
    }

    return result;
}

int solution(string name)
{
    int answer = 0;

    // Replace
    for (auto i = 0; i < name.size(); i++)
    {
        if (name[i] != 'A')
            answer += min(name[i] - 'A', 'Z' + 1 - name[i]);
    }

    // Move
    int notACount = 0;

    for (auto n : name)
    {
        if (n == 'A')
            continue;

        notACount++;
    }

    // Only contains A
    if (notACount == 0)
        return answer;

    int pos = 0;
    while (notACount > 0)
    {
        // Replace current pos first
        name[pos] = 'A';
        notACount--;

        int left = getLeftTarget(pos, name);
        int right = getRightTarget(pos, name);

        // No more letters to replace
        if (left < 0 && right < 0)
            break;

        int leftDist = pos - left;
        int rightDist = right - pos;

        if (leftDist < 0)
            leftDist += name.size();

        if (rightDist < 0)
            rightDist += name.size();

        if (leftDist < rightDist)
        {
            answer += leftDist;
            pos = left;
        }
        else
        {
            answer += rightDist;
            pos = right;
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution("AAZZZZ") << endl;
    return 0;
}
