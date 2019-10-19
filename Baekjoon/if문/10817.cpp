#include <iostream>

using namespace std;

int main(void)
{
    int num[3];
    
    cin >> num[0] >> num[1] >> num[2];

    for (int i = 0 ; i < 2 ; i++)
    {
        for (int j = 1 ; j < 3 ; j++)
        {
            int temp;
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    cout << num[1] << endl;
    return 0;
}
