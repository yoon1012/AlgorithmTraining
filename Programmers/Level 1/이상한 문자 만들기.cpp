#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s)
{
    string answer = "";
    int index = 0;

    for (int i = 0 ; i < s.length() ; i++)
    {
        if (index % 2 == 0)
        {
            s.at(i) = toupper(s.at(i));
        }
        else
        {
            s.at(i) = tolower(s.at(i));
        }
        
        if (s.at(i) == ' ') index = -1;
        index++;
    }
    
    answer = s;
    return answer;
}
