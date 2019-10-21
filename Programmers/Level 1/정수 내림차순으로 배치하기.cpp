#include <string>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

long long solution(long long n)
{
    string nString = to_string(n);
    vector<char> nStringVector;
    
    for (char nChar : nString)
    {
        nStringVector.push_back(nChar);
    }
    
    sort(nStringVector.begin(), nStringVector.end(), cmp);
    nString = "";
    
    for (char nChar : nStringVector)
    {
        nString += nChar;
    }
    
    long long answer = atoll(nString.c_str());
    return answer;
}
