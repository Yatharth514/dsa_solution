class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        sort(people.begin(), people.end());
        int boat = 0;

        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (cur == 0)
            {
                boat++;
                cur = cur + people[i];
            }
            else if (cur + people[i] <= limit && cur != 0)
            {
                cur = 0;
            }
            else
            {
                boat++;
                cur = cur + people[i];
            }
        }
        return boat;
    }
};