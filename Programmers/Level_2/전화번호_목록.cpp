// 해시
// 01-12-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    // 접근은 맞게 했는데 최소 길이보다 긴 길이의 접두어에 대한 생각을 못했다.
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}
