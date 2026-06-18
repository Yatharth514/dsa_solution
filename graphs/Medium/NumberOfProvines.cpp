class Solution
{
public:
    void dfs(int i, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited)
    {
        visited[i] = true;
        for (auto &it : adj[i])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        int c = 0;
        int n = isConnected.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                c++;
            }
        }

        return c;
    }
};