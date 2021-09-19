#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<string> text;
	text.push_back("aaaaaaaaaa aaaaaaaaa aaaaaa");
	text.push_back("");
	text.push_back("bbbbbbbbbbbbbb bbbbbbbbbbb bbbbbbbbbbbbb");

	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
	{
		for (auto& c : *it)
		{
			if (isalpha(c)) c = toupper(c);
		}
	}

	for (auto it : text)
	{
		cout << it << endl;
	}

	vector<int> number(10, 42);

	for (auto& nu : number)
	{
		nu = nu * 2;
		cout << nu << endl;
	}

	return 0;
}