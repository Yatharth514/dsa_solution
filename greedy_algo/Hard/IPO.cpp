class cmp
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = capital.size();
        vector<vector<int>> p;
        for (int i = 0; i < n; i++)
        {
            p.push_back({capital[i], profits[i]});
        }
        sort(p.begin(), p.end(), cmp());
        priority_queue<int> pq;
        int j = 0;
        int t = 0;
        if (w < p[0][0])
            return w;
        if (k > n)
        {
            k = n;
        }
        while (t < k)
        {
            while (j < n && p[j][0] <= w)
            {
                pq.push(p[j][1]);
                j++;
            }
            if (!pq.empty())
            {
                w += pq.top();
                t++;
                pq.pop();
            }
            else
                break;
        }

        return w;
    }
};