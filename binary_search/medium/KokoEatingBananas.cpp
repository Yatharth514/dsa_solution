class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int k)
    {
        int n = piles.size();
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++)
            maxm = max(piles[i], maxm);

        int l = 1;
        int h = maxm;
        int ans = INT_MAX;
        int mid = 0;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (piles[i] % mid == 0)
                    sum += (piles[i] / mid);
                else
                    sum += (piles[i] / mid) + 1;
            }
            if (sum <= k)
            {
                if (ans > mid)
                    ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};