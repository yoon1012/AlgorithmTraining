#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    
    for (int i = 0 ; i < commands.size() ; i++)
    {
        auto command = commands[i];
        
        int p = command[0] - 1;
        int q = command[1] - 1;
        int r = command[2] - 1;
                
        vector<int> result;

        for (int j = p ; j < q + 1 ; j++)
            result.push_back(array[j]);
        
        sort(result.begin(), result.end());
        answer.push_back(result[r]);
    }
    
    return answer;
}
