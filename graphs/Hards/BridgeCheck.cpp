class Solution
{
public:
    void dfs(int node, int parent, int &timer, int c, int d, unordered_map<int, vector<int>> &adjl, vector<int> &disc, vector<int> &low, vector<int> &visited, bool &result)
    {
        visited[node] = 1;
        disc[node] = timer;
        low[node] = timer;
        timer++;
        for (auto &it : adjl[node])
        {
            if (parent == it)
                continue;
            if (!visited[it])
            {
                dfs(it, node, timer, c, d, adjl, disc, low, visited, result);
                low[node] = min(low[node], low[it]);
                if (low[it] > disc[node])
                {
                    if ((it == c && node == d) || (node == c && it == d))
                        result = true;
                }
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
    {
        // Code here
        unordered_map<int, vector<int>> adjl;
        int parent = -1;
        int timer = 0;
        vector<int> visited(V, 0);
        vector<int> disc(V);
        vector<int> low(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        for (int i = 0; i < V; i++)
        {
            disc[i] = -1;
            low[i] = -1;
        }
        bool result = false;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, timer, c, d, adjl, disc, low, visited, result);
            }
        }
        return result;
    }
};