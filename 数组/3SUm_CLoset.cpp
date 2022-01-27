//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[nums.size() - 1], value = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                value = nums[i] + nums[left] + nums[right];
                if (target > value)
                    left++;
                else if (target < value)
                    right--;
                else
                    return target;
                if (abs(target - value) < abs(target - result)) {
                    result = value;
                }
            }
        }
        return result;
    }
};