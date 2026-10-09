class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int l = 1;
        int h = c;
        int sqrt = 0;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (mid == c / mid)
            {
                sqrt = mid;
                break;
            }
            else if (mid < c / mid)
                l = mid + 1;
            else
                h = mid - 1;
        }
        int r;
        if (sqrt == 0)
            r = l - 1;
        else
            r = sqrt;

        l = 0;
        while (l <= r)
        {
            long long sum = static_cast<long long>(pow(l, 2)) + static_cast<long long>(pow(r, 2));
            if (sum == c)
                return true;
            else if (sum > c)
                r--;
            else
                l++;
        }
        return false;
    }
};