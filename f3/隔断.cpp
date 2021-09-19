#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string result1, result2, str1, str2;
	while (cin >> str1>>str2)
	{
		result1 += str1;
		result2 += str2 + " ";
	}
	cout<< result1 << endl;
	cout<< result2 << endl;

	return 0;
}