#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

//改成char 后原来的值不会变
int main() 
{
	string s = "nimasile nihao";
	for (auto &n: s)
	{
		n = 'X';
	}
	cout << s << endl;
	cx                        
	//也可以用for和while
	decltype(s.size()) i = 0;
	while (i != s.size())
	{
		s[i] = 'G';
		++i;
	}
	cout << s << endl;
	for (i = 0; i != s.size(); ++i)
	{
		s[i] = 'Y';
	}
	cout << s << endl;
	return 0;
}