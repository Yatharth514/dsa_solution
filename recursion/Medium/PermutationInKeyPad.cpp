class Solution
{
public:
    void solve(string digits, vector<string> &b, int i, string str, unordered_map<char, string> &mpp, int n)
    {
        if (str.length() == n)
        {
            b.push_back(str);
            return;
        }
        for (auto &it : mpp[digits[i]])
        {
            str += it;
            solve(digits, b, i + 1, str, mpp, n);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        vector<string> b;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string str = "";
        int i = 0;
        solve(digits, b, i, str, mpp, n);
        return b;
    }
};