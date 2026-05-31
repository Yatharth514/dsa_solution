class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int n = asteroids.size();
        long long sum = (long long)mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] > sum)
                return false;
            else
                sum += asteroids[i];
        }
        return true;
    }
};