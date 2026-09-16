class Solution
{
public:
    int findCheapestPrice(int m, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int n = flights.size();
        unordered_map<int, vector<pair<int, int>>> mpp;
        for (int i = 0; i < n; i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            mpp[u].push_back(make_pair(v, d));
        }
        vector<int> dist(m, INT_MAX);
        dist[src] = 0;
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {src, 0}});
        while (!st.empty())
        {
            auto f = *(st.begin());
            st.erase(st.begin());
            int stops = f.first;
            int node = f.second.first;
            int dis = f.second.second;
            for (auto &it : mpp[node])
            {
                if (dist[it.first] > it.second + dis && stops <= k)
                {
                    dist[it.first] = it.second + dis;
                    st.insert({stops + 1, {it.first, dist[it.first]}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};