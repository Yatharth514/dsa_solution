class Solution
{
public:
    void bfs(unordered_map<int, vector<int>> &rev, vector<int> &outdegree, vector<int> &ans, int n)
    {

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (outdegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (auto &it : rev[f])
            {
                outdegree[it]--;
                if (outdegree[it] == 0)
                    q.push(it);
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        unordered_map<int, vector<int>> rev;
        int n = graph.size();
        for (int i = 0; i < n; i++)
        {
            for (auto &it : graph[i])
                rev[it].push_back(i);
        }
        vector<int> outdegree;
        for (int i = 0; i < n; i++)
        {
            outdegree.push_back(graph[i].size());
        }
        vector<int> ans;
        bfs(rev, outdegree, ans, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};