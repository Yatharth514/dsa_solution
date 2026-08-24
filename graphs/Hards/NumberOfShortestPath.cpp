class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int k = roads.size();
        const long long MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> mpp;
        for (int i = 0; i < k; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            mpp[u].push_back(make_pair(v, w));
            mpp[v].push_back(make_pair(u, w));
        }
        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;
        set<pair<long long, int>> st;
        st.insert({0, 0});
        while (!st.empty())
        {
            auto f = *(st.begin());
            long long dist = f.first;
            int top = f.second;
            st.erase(st.begin());

            for (auto &it : mpp[top])
            {
                if (distance[it.first] > it.second + dist)
                {
                    auto record = st.find(make_pair(distance[it.first], it.first));
                    if (record != st.end())
                        st.erase(record);
                    distance[it.first] = it.second + dist;
                    st.insert({distance[it.first], it.first});
                    ways[it.first] = ways[top];
                }
                else if (distance[it.first] == it.second + dist)
                {
                    ways[it.first] = (ways[it.first] + ways[top]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};