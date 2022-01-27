class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x, mid, result;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (mid * mid == x)
            {
                result = mid;
                break;
            }
            if (mid * mid < x)
            {
                left = mid + 1;
                result = mid;
            }
            else {
                right = mid - 1;
            }

        }
        return result;
    }
};