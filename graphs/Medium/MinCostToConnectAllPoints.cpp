class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> mpp;
        for (int u = 0; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                mpp[u].push_back(make_pair(v, dist));
                mpp[v].push_back(make_pair(u, dist));
            }
        }
        vector<int> key(n, INT_MAX);
        vector<int> mst(n, 0);
        vector<int> parent(n, -1);
        key[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            int minm = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (minm > key[j] && mst[j] == 0)
                {
                    minm = key[j];
                    u = j;
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