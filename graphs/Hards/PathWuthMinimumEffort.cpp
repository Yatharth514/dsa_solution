class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                minm = min(heights[i][j], minm);
                maxm = max(heights[i][j], maxm);
            }
        }
        if (maxm == minm)
            return 0;
        int diff = maxm - minm;
        int l = 0;
        int h = maxm - minm;
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        int k = 4;
        int ans = 0;
        int x;
        while (l <= h)
        {
            x = (l + h) / 2;
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[0][0] = true;
            bool flag = false;
            q.push({0, 0});
            while (!q.empty())
            {
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                for (int i = 0; i < k; i++)
                {
                    int nr = sr + delRow[i];
                    int nc = sc + delCol[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && abs(heights[nr][nc] - heights[sr][sc]) <= x && !visited[nr][nc])
                    {
                        visited[nr][nc] = true;
                        if (nr == n - 1 && nc == m - 1)
                        {
                            flag = true;
                            break;
                        }
                        q.push({nr, nc});
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
            {
                h = x - 1;
                ans = x;
            }
            else
                l = x + 1;
        }
        return ans;
    }
};