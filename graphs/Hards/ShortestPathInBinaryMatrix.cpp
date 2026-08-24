class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && grid[0][0] == 0)
            return 1;
        else if (n == 1 && grid[0][0] == 1)
            return -1;
        if (grid[0][0] != grid[n - 1][m - 1])
            return -1;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = 0;
        int row[] = {1, -1, 0, 0, -1, 1, 1, -1};
        int col[] = {0, 0, 1, -1, -1, 1, -1, 1};
        int k = 8;
        q.push({1, {0, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int sr = it.second.first;
            int sc = it.second.second;
            for (int i = 0; i < k; i++)
            {
                int nr = sr + row[i];
                int nc = sc + col[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && distance[nr][nc] > 1 + dist)
                {
                    distance[nr][nc] = dist + 1;
                    if (nr == n - 1 && nc == m - 1)
                        return dist + 1;
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};