class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + nums[i];
        }
        vector<int> ans;
        int left, right;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans.push_back(suf[i + 1] - nums[i] * (n - 1 - i));
            }
            else if (i == n - 1)
            {
                ans.push_back(nums[i] * i - pre[i - 1]);
            }
            else
            {
                left = nums[i] * i - pre[i - 1];
                right = suf[i + 1] - nums[i] * (n - 1 - i);
                ans.push_back(left + right);
            }
        }
        return ans;
    }
};
//In this we use prefix sum and suffix sum and apply the formula of 
//int left =nums[i]*i-pre[i-1]for j<i
//int right=suf[i+1]-nums[i]*(n-1-i)
