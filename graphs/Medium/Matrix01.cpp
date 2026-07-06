class Solution
{
public:
    void bfs(vector<vector<int>> &ans, vector<vector<bool>> &visited)
    {
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ans[i][j] == 0)
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

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && ans[nr][nc] != 0)
                    {
                        ans[nr][nc] = ans[sr][sc] + 1;
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
                visited[sr][sc] = true;
            }
        }
        return;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    ans[i][j] = -1;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        bfs(ans, visited);
        return ans;
    }
};