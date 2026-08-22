class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        unordered_map<int, vector<pair<int, int>>> mpp;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            pair<int, int> p = make_pair(v, w);
            mpp[u].push_back(p);
            mpp[v].push_back(make_pair(u, w));
        }
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty())
        {
            auto f = *(s.begin());
            int top = f.second;
            int dista = f.first;
            s.erase(s.begin());

            for (auto &it : mpp[top])
            {
                if (dist[it.first] > it.second + dista)
                {
                    auto record = s.find(make_pair(dist[it.first], it.first));
                    if (record != s.end())
                        s.erase(record);
                    dist[it.first] = it.second + dista;
                    s.insert(make_pair(dist[it.first], it.first));
                }
            }
        }
        return dist;
    }
};