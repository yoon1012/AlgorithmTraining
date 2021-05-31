// 동적계획법
// 05-31-2021

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[101][101];

// 더할 때 계속 나머지를 구해줘야 한다.
int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    
    for (int i = 0 ; i < puddles.size() ; i++)
    {
        int pi = puddles[i][1] - 1;
        int pj = puddles[i][0] - 1;
        
        d[pi][pj] = -1;
    }
    
    d[0][0] = 1;
    
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            
            if (d[i][j] == -1)
            {
                continue;
            }
            
            if (i == 0)
            {
                if (d[i][j-1] > 0)
                {
                    d[i][j] += d[i][j-1] % 1000000007;
                }
            }
            else if (j == 0)
            {
                if (d[i-1][j] > 0)
                {
                    d[i][j] += d[i-1][j] % 1000000007;
                }
            }
            else
            {
                if (d[i][j-1] > 0)
                {
                    d[i][j] += d[i][j-1] % 1000000007;
                }
                
                if (d[i-1][j] > 0)
                {
                    d[i][j] += d[i-1][j] % 1000000007;
                }
            }
        }
    }
    
    answer = d[n-1][m-1];
    
    return answer % 1000000007;
}

int main(void)
{
    int answer = solution(4, 3, {{2,2}});
    cout << answer << endl;
    return 0;
}
