#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool sortStrings(string a, string b)
{
    if (a.at(N) == b.at(N))
    {
        return a < b;
    }
    else
    {
        return a.at(N) < b.at(N);
    }
}

vector<string> solution(vector<string> strings, int n)
{
    N = n;
    
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), sortStrings);
    
    return answer;
}
