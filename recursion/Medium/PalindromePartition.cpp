class Solution
{
public:
    void solve(string s, int n, vector<string> &c, vector<vector<string>> &b, int start)
    {
        if (start == n)
        {
            b.push_back(c);
            return;
        }
        for (int i = start + 1; i <= n; i++)
        {
            string k = s.substr(start, i - start);

            int flag = 0;
            for (int j = 0; j < k.length(); j++)
            {
                if (k[j] != k[k.length() - 1 - j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            else
            {
                c.push_back(k);
                solve(s, n, c, b, i);
                c.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<string>> b;
        vector<string> c;
        int start = 0;
        solve(s, n, c, b, start);
        return b;
    }
};