#include<iostream>

int main() {
	short svalue = 32767; ++svalue; // -32768
	std::cout << svalue << std::endl;
	unsigned uivalue = 0; --uivalue;  // 4294967295
	std::cout << uivalue << std::endl;
	unsigned short usvalue = 65535; ++usvalue;  // 0
	std::cout << usvalue << std::endl;
}
