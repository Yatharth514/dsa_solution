class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();
        vector<int> letters(26, 0);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            letters[ch - 'a'] = i;
        }

        int last = letters[s[0] - 'a'];
        int len = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            len++;
            if (last < letters[s[i] - 'a'])
            {
                last = letters[s[i] - 'a'];
            }
            if (last == i)
            {

                last = -1;
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};