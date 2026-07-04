class Solution
{
public:
    void dfs(int i, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adjl, stack<int> &s)
    {
        visited[i] = true;
        for (auto &it : adjl[i])
        {
            if (!visited[it])
            {
                dfs(it, visited, adjl, s);
            }
        }
        s.push(i);
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<int>> adjl;
        unordered_map<int, bool> visited;
        stack<int> s;
        int n = edges.size();

        for (int i = 0; i < n; i++)
        {
            adjl[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adjl, s);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};