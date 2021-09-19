#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<string> kzisb;
	string i;
	while (cin >> i)
	{
		kzisb.push_back(i);
	}
	for (auto &ssd : kzisb)
	{
		for (auto& c : ssd)
		{
			c = toupper(c);
		}
	}
	for (auto i:kzisb)
	{
		cout << i << endl;
	}
	
	return 0;

}