#include <iostream>

int main()
{
	int ival = 42;
	int *p = &ival;
	std::cout << *p << std::endl;
	*p = 0;
	std::cout << *p << std::endl;
	std::cout << ival << std::endl;

	int i = 5, & ri = i;
	std::cout << ri << std::endl;
	std::cout << i << std::endl;
	ri = 10;
	std::cout << ri << std::endl;
	std::cout << i << std::endl;
	
	//编写代码分别改变指针的值以及指针所指对象的值。
	int a = 0, b = 1;
	int *p1 = &a, * p2 = p1;
	std::cout << *p1 << std::endl;
	std::cout << *p2<< std::endl;
	p1 = &b;
	*p2 = b;
	std::cout << a << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;

}