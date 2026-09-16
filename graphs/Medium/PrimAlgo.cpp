class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<pair<int, int>>> mpp;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mpp[u].push_back(make_pair(v, w));
            mpp[v].push_back(make_pair(u, w));
        }
        vector<int> key(V, INT_MAX);
        vector<int> mst(V, 0);
        vector<int> parent(V, -1);
        key[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < V; i++)
        {
            int mini = INT_MAX;
            int u = -1;
            for (int i = 0; i < V; i++)
            {
                if (mini > key[i] && mst[i] == 0)
                {
                    mini = key[i];
                    u = i;
                }
            }
            if (u == -1)
                break;
            mst[u] = 1;
            for (auto &it : mpp[u])
            {
                if (key[it.first] > it.second && mst[it.first] == 0)
                {
                    key[it.first] = it.second;
                    parent[it.first] = u;
                }
            }
        }
        int sum = 0;
        for (int x : key)
        {
            sum += x;
        }
        return sum;
    }
};