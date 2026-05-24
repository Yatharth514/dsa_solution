class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        int n = players.size();
        int m = trainers.size();
        int i = 0;
        int j = 0;
        int c = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while (i < n && j < m)
        {
            if (trainers[j] >= players[i])
            {
                c++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return c;
    }
};