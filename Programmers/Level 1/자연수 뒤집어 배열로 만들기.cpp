#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(long long n)
{    
    vector<int> answer;
    string nString = to_string(n);

    for (int i = nString.length() - 1 ; i >= 0 ; i--)
    {
        int digit;
        string digitString;
        digitString.push_back(nString.at(i));
            
        stringstream ss(digitString);
        ss >> digit;
        
        answer.push_back(digit);
    }
    
    return answer;
}
