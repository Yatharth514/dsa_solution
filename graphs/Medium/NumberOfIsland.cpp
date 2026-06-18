class Solution
{
public:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int delRow[] = {-1, 1, 0, 0};
            int delCol[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++)
            {
                int nr = i + delRow[k];
                int nc = j + delCol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' &&
                    !visited[nr][nc])
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, visited);
                    c++;
                }
            }
        }
        return c;
    }
};