class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> ans(n);
        unordered_map<int, vector<long long>> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]].push_back(i);
        }
        for (auto it : mpp)
        {
            vector<long long> &rep = it.second;
            long long k = rep.size();
            if (k != 1)
            {
                vector<long long> pre(k);
                vector<long long> suf(k);
                pre[0] = rep[0];
                suf[k - 1] = rep[k - 1];
                for (long long i = 1; i < k; i++)
                {
                    pre[i] = pre[i - 1] + rep[i];
                }
                for (long long i = k - 2; i >= 0; i--)
                {
                    suf[i] = suf[i + 1] + rep[i];
                }
                long long left, right;
                for (long long i = 0; i < k; i++)
                {
                    if (i == 0)
                    {
                        ans[rep[i]] = suf[i + 1] - rep[i] * (k - i - 1);
                    }
                    else if (i == k - 1)
                    {
                        ans[rep[i]] = rep[i] * i - pre[i - 1];
                    }
                    else
                    {
                        left = rep[i] * i - pre[i - 1];
                        right = suf[i + 1] - rep[i] * (k - i - 1);
                        ans[rep[i]] = left + right;
                    }
                }
            }
            else
            {
                ans[rep[0]] = 0;
            }
        }
        return ans;
    }
};