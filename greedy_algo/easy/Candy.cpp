class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int c = 0;
        int total = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (c == 2)
            {
                c = 0;
                continue;
            }
            else if (c < 2)
            {
                total += cost[i];
                c++;
            }
        }
        return total;
    }
};