#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> TwoSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int l = 0, r = nums.size();
    for (int i = 0; i < r - 1 && nums[i] <= 0; i++) {
        if (nums[i] == nums[i + 1]) continue;
        else if (nums[r - 1] + nums[r] <= target) { l = r - 1; continue; }

        else if (nums[l] + nums[l + 1] >= target) { r = l + 1; continue; }

        while (l < r) {
            int mid = (r + l) / 2;
            if (nums[l] + nums[r] == target) {
                vector<int>temp;
                temp[0] = nums[l];
                temp[1] = nums[r];
                ans.push_back(temp);
            }
            else if (nums[l] + nums[r] > target) {
                r--;
            }
            else
                l++;
        }
    }
    return ans;
}

vector<vector<int>> ThreeSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 1 && nums[i] <= 0; i++)
    {
        int new_tar = target - nums[i];
        vector<int> new_nums(nums.begin() + i, nums.end());
        vector<int> temp;
        temp = TwoSum(new_nums, new_tar);
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 1 && nums[i] <= 0; i++)
    {
        int new_tar = target - nums[i];
        vector<int> new_nums(nums.begin() + i, nums.end());
        vector<vector<int>> temp;
        temp = ThreeSum(new_nums, new_tar);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    int target = 0;
    int a[6] = { 1, 0, -1, 0, -2, 2 };
    vector<int> b;
    b.insert(b.begin(), a, a + 6);
    ThreeSum(b, target);
}