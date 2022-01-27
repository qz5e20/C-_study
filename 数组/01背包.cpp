#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>;

using namespace std;

void test_1_wei_bag_problem() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bgWeight = 4;

	vector<int> dp(bgWeight + 1, 0);
	for (int i = 0; i < weight.size(); i++) {
		for (int j = bgWeight; j >= weight[i];j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[bgWeight] << endl;
}

int main() {
	test_1_wei_bag_problem();
}