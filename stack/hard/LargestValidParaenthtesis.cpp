class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int c = 0;
        stack<int> p;
        p.push(-1);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == ')')
            {
                if (p.top() == -1)
                {
                    p.pop();
                    p.push(i);
                    continue;
                }
                else
                {
                    if (s[p.top()] == '(')
                    {
                        p.pop();
                        c = max(i - p.top(), c);
                    }
                    else
                    {
                        p.pop();
                        p.push(i);
                    }
                }
            }
            else if (ch == '(')
            {
                p.push(i);
            }
        }
        return c;
    }
};