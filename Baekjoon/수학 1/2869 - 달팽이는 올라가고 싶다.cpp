#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long a, b, v;
	cin >> a >> b >> v;
    
	cout << (long long)ceil((double)(v - a) / (a - b)) + 1 << endl;
	return 0;
}
