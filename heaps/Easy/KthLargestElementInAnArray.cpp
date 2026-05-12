class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push(nums[i]);
        }

        for (int i = 1; i < k; i++)
        {
            mp.pop();
        }
        return mp.top();
    }
};