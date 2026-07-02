class Solution
{
public:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, int m, int time)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                int row[] = {1, -1, 0, 0};
                int col[] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++)
                {
                    int nr = sr + row[i];
                    int nc = sc + col[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }
        return time;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int time = 0;
        int c = 0;
        time = bfs(grid, visited, n, m, time);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
                else if (grid[i][j] == 0)
                    c++;
            }
        }
        if (c == n * m)
            return 0;
        return time - 1;
    }
};