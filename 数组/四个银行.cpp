#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<pair<int, int> > vCoordinate;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    int countnums[4] = { 0 };
    vector<int> finaltime(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            countnums[0] ++;
            finaltime[i] = countnums[0] * 5;
        }
        else if (nums[i] == 2) {
            countnums[1] ++;
            finaltime[i] = countnums[1] * 10;
        }
        else if (nums[i] == 3) {
            countnums[2] ++;
            finaltime[i] = countnums[2] * 15;
        }
        else if (nums[i] == 4) {
            countnums[3] ++;
            finaltime[i] = countnums[3] * 20;
        }
    }

    vCoordinate vCoor;
    for (int i = 0; i < nums.size(); ++i) {
        vCoor.push_back(vCoordinate::value_type(finaltime[i], i));//´æ´¢×ø±êÊý¾Ý
    }
    sort(vCoor.begin(), vCoor.end(), cmp);
    for (int i = 0; i < nums.size(); ++i) {
        cout << vCoor[i].second << ' ';
    }
    cout << endl;
    return 0;
}