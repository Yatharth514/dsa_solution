class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int n = houses.size();
        int m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxm = INT_MIN;
        int minm = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int house = houses[i];
            int l = 0;
            int mid = 0;
            int h = m - 1;
            while (l < h)
            {
                mid = l + (h - l) / 2;
                if (heaters[mid] <= house)
                    l = mid + 1;
                else
                    h = mid;
            }
            int index = h - 1;
            if (h == 0)
            {
                minm = abs(heaters[h] - house);
                maxm = max(minm, maxm);
            }
            else
            {
                minm = min(abs(heaters[h] - house), abs(heaters[index] - house));
                maxm = max(minm, maxm);
            }
        }
        return maxm;
    }
};