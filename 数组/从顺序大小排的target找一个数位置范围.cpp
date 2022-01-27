class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            const int mid = (left + right) / 2;
            if (nums[mid] == target) {
                int start = mid, end = mid;
                while (start >= 0 && nums[start] == target) start--;
                while (end < size && nums[end] == target) end++;
                return { start + 1, end - 1 };
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return { -1, -1 };
    }
};