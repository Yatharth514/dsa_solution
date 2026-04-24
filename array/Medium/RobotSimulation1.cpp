class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int x = 0;
        int y = 0;
        unordered_map<long, set<long>> mpp;
        vector<int> dir = {1, 2, 3, 4};
        int k = 0;
        int direction = dir[0];
        int maxm = 0;
        for (int i = 0; i < obstacles.size(); i++)
        {
            mpp[obstacles[i][0]].insert(obstacles[i][1]);
        }
        int n = commands.size();
        for (int i = 0; i < n; i++)
        {
            if (commands[i] == -1)
            {
                k = (k + 1) % 4;
                direction = dir[k];
                continue;
            }
            else if (commands[i] == -2)
            {
                k = (dir.size() - 1 + k) % 4;
                direction = dir[k];
                continue;
            }

            if (direction == 1)
            {
                while (commands[i]--)
                {
                    if (mpp.find(x) != mpp.end())
                    {
                        if (mpp[x].find(y + 1) != mpp[x].end())
                        {
                            break;
                        }
                    }
                    y++;
                }
            }
            else if (direction == 2)
            {
                while (commands[i]--)
                {
                    if (mpp.find(x + 1) != mpp.end())
                    {
                        if (mpp[x + 1].find(y) != mpp[x + 1].end())
                        {
                            break;
                        }
                    }
                    x++;
                }
            }
            else if (direction == 3)
            {
                while (commands[i]--)
                {
                    if (mpp.find(x) != mpp.end())
                    {
                        if (mpp[x].find(y - 1) != mpp[x].end())
                        {
                            break;
                        }
                    }
                    y--;
                }
            }
            else
            {
                while (commands[i]--)
                {
                    if (mpp.find(x - 1) != mpp.end())
                    {
                        if (mpp[x - 1].find(y) != mpp[x - 1].end())
                        {
                            break;
                        }
                    }
                    x--;
                }
            }
            maxm = max(maxm, (x * x + y * y));
        }
        return maxm;
    }
};