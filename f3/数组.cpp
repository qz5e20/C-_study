#include <vector>
#include <iostream>
using std::cout; 
using std::vector;
using std::endl;

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

	return 0;

	int arr1[10];
	for (int i = 0; i < 10; i++) arr1[i] = arr[i];

	vector<int> v(10);
	for (int i = 0; i != 10; i++) v[i] = arr[i];
	vector<int> v2(v);
	for (auto i : v2) cout << i << " ";
	cout << endl;

}