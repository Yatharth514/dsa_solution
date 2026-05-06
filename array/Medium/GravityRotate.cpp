class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        int flag = -1;
        int r = 0;
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                if (boxGrid[i][j] == '.')
                {
                    if (flag == -1)
                    {
                        r = i;
                        c = j;
                        flag = 0;
                    }
                }

                if (boxGrid[i][j] == '#')
                {
                    if (flag == 0)
                    {
                        swap(boxGrid[i][j], boxGrid[r][c]);
                        c--;
                    }
                }
                if (boxGrid[i][j] == '*')
                {
                    flag = -1;
                }
            }
            flag = -1;
            r = 0;
            c = 0;
        }
        vector<vector<char>> rotBox(m, vector<char>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotBox[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        return rotBox;
    }
};
// using flag system and taking the initial coordinates of the space and replacing it with the stone until we hit obstacle.
