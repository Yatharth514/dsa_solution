class Solution
{
public:
    void check(vector<vector<bool>> &visited, vector<vector<char>> &board, int n, int m, int sr, int sc)
    {
        visited[sr][sc] = true;
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        int k = 4;
        for (int i = 0; i < k; i++)
        {
            int nr = sr + row[i];
            int nc = sc + col[i];
            if (nr >= 0 & nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !visited[nr][nc])
                check(visited, board, n, m, nr, nc);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                    check(visited, board, n, m, i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};