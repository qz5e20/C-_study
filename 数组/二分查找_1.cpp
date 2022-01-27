
#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int binary_search(vector<int>&nums,int target) {
	sort(nums.begin(), nums.end());
	int left = 0;
	int right = nums.size() - 1;

	//mid可以将定义放在循环内
	while (left < right) {
		int mid = (left + right) / 2;
		if (target == nums[mid]) {
			cout << "The place at " << mid + 1 << endl;
			return mid;
		}
		else if (target<nums[mid])
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	cout << "no result" << endl;
	return -1;
}

int main() {
	int  target = 2;
	vector<int> nums;
	int i = 0;
	for (i = 0; i < 10; i++){
		nums.push_back(i);//把元素一个一个存入到vector中
		cout << nums[i];
	}
	cout << endl;
	binary_search(nums, target);
}