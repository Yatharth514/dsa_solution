class Solution
{
public:
    void unionSet(int pu, int pv, vector<int> &parent, vector<int> &ranks)
    {
        int u = findParent(pu, parent);
        int v = findParent(pv, parent);
        if (ranks[u] < ranks[v])
        {
            parent[u] = v;
        }
        else if (ranks[v] < ranks[u])
            parent[v] = u;
        else
        {
            ranks[u]++;
            parent[v] = u;
        }
    }
    int findParent(int u, vector<int> &parent)
    {
        if (parent[u] == u)
            return u;
        else
        {
            int k = findParent(parent[u], parent);
            parent[u] = k;
            return k;
        }
    }
    void makeSet(vector<int> &parent, vector<int> &ranks, int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int components = n;
        vector<int> ranks(n);
        vector<int> parent(n);
        makeSet(parent, ranks, n);
        int extras = 0;
        int k = connections.size();
        for (int i = 0; i < k; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            if (findParent(u, parent) == findParent(v, parent))
                extras++;
            else
            {
                components--;
                unionSet(u, v, parent, ranks);
            }
        }
        if (extras < components - 1)
            return -1;
        return components - 1;
    }
};