class Solution
{
public:
    void makeSet(vector<int> &parent, int n, vector<vector<int>> &grid)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                parent[i * n + j] = i * n + j;
            }
        }
    }
    int makingLarger(vector<vector<int>> &grid, int n, int sr, int sc, vector<int> &parent, vector<int> &isLandSize)
    {
        int sum = 1;
        int k = 4;
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        set<int> st;
        for (int i = 0; i < k; i++)
        {
            int nr = sr + row[i];
            int nc = sc + col[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
            {
                st.insert(parent[nr * n + nc]);
            }
        }
        while (!st.empty())
        {
            auto it = *(st.begin());
            st.erase(st.begin());
            sum += isLandSize[it];
        }
        return sum;
    }
    int findUnion(vector<vector<int>> &grid, int n, int sr, int sc, vector<int> &parent, int c, vector<vector<bool>> &visited)
    {
        c++;
        visited[sr][sc] = true;
        int k = 4;
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        for (int i = 0; i < k; i++)
        {
            int nr = sr + row[i];
            int nc = sc + col[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && parent[nr * n + nc] == nr * n + nc && !visited[nr][nc])
            {
                parent[nr * n + nc] = parent[sr * n + sc];
                c = findUnion(grid, n, nr, nc, parent, c, visited);
            }
        }
        return c;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> parent(n * n);
        vector<int> isLandSize(n * n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        makeSet(parent, n, grid);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && parent[i * n + j] == i * n + j)
                    isLandSize[i * n + j] = findUnion(grid, n, i, j, parent, 0, visited);
            }
        }
        vector<int> zeroes(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    zeroes[i * n + j] = makingLarger(grid, n, i, j, parent, isLandSize);
                }
            }
        }
        int maxm = 0;
        for (int i = 0; i < n * n; i++)
        {
            maxm = max(maxm, zeroes[i]);
        }
        if (maxm == 0)
            return n * n;
        return maxm;
    }
};