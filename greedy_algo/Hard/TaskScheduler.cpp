class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int k = tasks.size();
        unordered_map<char, int> mpp;
        for (int i = 0; i < k; i++)
        {
            mpp[tasks[i]]++;
        }
        int maxFreq = 0;
        for (auto &it : mpp)
        {
            maxFreq = max(maxFreq, it.second);
        }
        int c = 0;
        for (auto &it : mpp)
        {
            if (it.second == maxFreq)
                c++;
        }
        int ans = max(k, (maxFreq - 1) * (n + 1) + c);
        return ans;
    }
};