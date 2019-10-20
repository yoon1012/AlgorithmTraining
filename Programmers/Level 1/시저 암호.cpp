#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";
    
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s.at(i) == ' ') continue;
        
        if (s.at(i) >= 'A' && s.at(i) <= 'Z')
        {
            int index = s.at(i) - 'A';
            index += n;
            
            if (index > 25) index -= 26;
            s.at(i) = index + 'A';
        }
        
        if (s.at(i) >= 'a' && s.at(i) <= 'z')
        {
            int index = s.at(i) - 'a';
            index += n;
            
            if (index > 25) index -= 26;
            s.at(i) = index + 'a';
        }
    }
    
    answer = s;
    
    return answer;
}
