class Solution
{
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &visited, vector<int> &ap, unordered_map<int, vector<int>> &adjl)
    {
        visited[node] = 1;
        disc[node] = timer;
        low[node] = timer;
        timer++;
        int child = 0;
        for (auto &it : adjl[node])
        {
            if (parent == it)
                continue;
            if (!visited[it])
            {
                dfs(it, node, timer, disc, low, visited, ap, adjl);
                low[node] = min(low[node], low[it]);
                if (low[it] >= disc[node] && parent != -1)
                {
                    ap[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
        }
        if (parent == -1 && child > 1)
            ap[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<int>> adjl;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<int> visited(V, 0);
        int parent = -1;
        int timer = 0;
        vector<int> ap(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, timer, disc, low, visited, ap, adjl);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (ap[i])
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};