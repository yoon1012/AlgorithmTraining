#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	std::string output = "";

	while (!cin.eof())
	{
		std::string input;
		getline(cin, input);
		output += input + '\n';
	}

	std::cout << output;

	return 0;
}
