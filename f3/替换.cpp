#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

//�ĳ�char ��ԭ����ֵ�����
int main() 
{
	string s = "nimasile nihao";
	for (auto &n: s)
	{
		n = 'X';
	}
	cout << s << endl;
	cx                        
	//Ҳ������for��while
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