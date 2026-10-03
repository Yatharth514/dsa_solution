class Solution
{
public:
    void solve(int n, int row, vector<int> &col, vector<vector<string>> &ans, vector<string> &c, vector<int> &dig1, vector<int> &dig2)
    {
        if (row == n)
        {
            ans.push_back(c);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (col[i] || dig1[row - i + n - 1] || dig2[row + i])
            {
                c[row][i] = '.';
                continue;
            }
            col[i] = 1;
            dig1[row - i + n - 1] = 1;
            dig2[row + i] = 1;
            c[row][i] = 'Q';
            solve(n, row + 1, col, ans, c, dig1, dig2);
            col[i] = 0;
            dig1[row - i + n - 1] = 0;
            dig2[row + i] = 0;
            c[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> c(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> dig1(2 * n - 1, 0);
        vector<int> dig2(2 * n - 1, 0);

        int row = 0;

        solve(n, row, col, ans, c, dig1, dig2);
        return ans;
    }
};