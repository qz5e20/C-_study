#include <iostream>
int main()
{
	int Currval = 0, val = 0;
	if (std::cin >> Currval) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == Currval)
				++cnt;
			else {
				std::cout << Currval << "Occurs"
					<< cnt << "times" << std::endl;
				Currval = val;
				cnt = 1;
			}
		}
		std::cout<<Currval<< "Occurs"
			<< cnt << "times" << std::endl;
	}
}