#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer = arr;
    int min = 0;
    
    for (int i = 0 ; i < answer.size() ; i++)
    {
        if (i == 0) continue;
        if (answer[min] > answer[i]) min = i;
    }
    
    answer.erase(answer.begin() + min);
    if (answer.size() == 0) answer.push_back(-1);
    
    return answer;
}
