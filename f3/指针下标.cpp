#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


bool compare(int* const pb1,int*const pe1, int* const  pb2, int* const pe2)
{
	if ((pe1 - pb1) != (pe2 - pb2))
		return false;
	else
	{
		for (int* i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
			if (*i != *j) return false;
	}
	return true;
}

int main()
{
	const int arr_size = 10;
	int arr[arr_size];
	for (auto ptr = arr; ptr != arr + arr_size; ++ptr) *ptr = 0;
	for (auto i : arr) cout << i << " ";
	cout << endl;

	int arr1[3] = { 0,1,2 };
	int arr2[3] = { 0,2,4 };

	if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
		cout << "equal" << endl;
	else
		cout << "no equal" << endl;

	vector<int> vec1 = { 0,1,2 };
	vector<int> vec2 = { 0,1,2 };

	if (vec1 == vec2)
		cout << "equal" << endl;
	else
		cout << "no equal" << endl;
	return 0;
}