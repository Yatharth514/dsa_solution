class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int n, int m, int c)
    {
        visited[i][j] = true;
        c++;
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++)
        {
            int nr = i + row[k];
            int nc = j + col[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                c = dfs(grid, nr, nc, visited, n, m, c);
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    c = max(dfs(grid, i, j, visited, n, m, 0), c);
                }
            }
        }
        return c;
    }
};