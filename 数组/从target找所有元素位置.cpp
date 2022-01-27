#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int pos = 0;
    int mid = (left + right) / 2;
    while (left < right) {
        if (target == nums[mid]) {
            pos = mid;
            left = right;
            break;
        }
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
        mid = (left + right) / 2;
    }


    vector<int> out_pos; //因为这个数组没有定义大小，所以会leedcode上会报错
    if (nums[pos] != nums[mid]) {
        return { -1,-1 };
    }
    else{
        for (int i = 0;i<(pos) ; i++) {
            if (((pos - i) >= 0) && (nums[pos - i] == nums[pos])) {
                out_pos.push_back(pos - i);
            }
            else
                break;
        }
        for (int j = 1; j < (nums.size() -pos); j++)
        {
            if (nums[pos] == nums[pos + j]) {
                out_pos.push_back(pos +j);
            }
            else
                break;
        }
        sort(out_pos.begin(), out_pos.end());
    }

    for (auto i = out_pos.begin(); i != out_pos.end(); i++) {
        std::cout << *i << ' ';
    }
    return out_pos;

    
}

int main() {
    int  target = 8;
    vector<int> nums = { 5,7,7,8,8,10};

    searchRange(nums, target);
}