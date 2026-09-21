class Solution
{
public:
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int findParent(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        else
        {
            int k = findParent(parent[i], parent);
            parent[i] = k;
            return k;
        }
    }
    void makeSet(vector<vector<int>> &stones, vector<int> &rank, vector<int> &parent, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int row = stones[i][0];
            int col = stones[i][1] + 10001;
            parent[row] = row;
            parent[col] = col;
            rank[row] = 0;
            rank[col] = 0;
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        if (n == 1)
            return 0;
        vector<int> rank(20002);
        vector<int> parent(20002);
        makeSet(stones, rank, parent, n);

        for (int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1] + 10001;
            if (findParent(r, parent) == findParent(c, parent))
                continue;
            else
            {
                unionSet(r, c, parent, rank);
            }
        }
        set<int> components;

        for (auto &stone : stones)
        {
            int row = stone[0];

            components.insert(findParent(row, parent));
        }
        return n - components.size();
    }
};