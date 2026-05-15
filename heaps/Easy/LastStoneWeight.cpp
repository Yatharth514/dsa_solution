class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size();
        if (n == 1)
            return stones[0];

        priority_queue<int> maxh;
        for (int i = 0; i < n; i++)
        {
            maxh.push(stones[i]);
        }

        while (!maxh.empty() && maxh.size() > 1)
        {
            int first = maxh.top();
            maxh.pop();
            int second = maxh.top();
            maxh.pop();
            if (first > second)
            {
                maxh.push(first - second);
            }
            else if (second > first)
            {
                maxh.push(second - first);
            }
        }
        if (!maxh.empty())
            return maxh.top();
        return 0;
    }
};