class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        int sum = 0;
        stack<int> st;
        st.push(0);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(')
                st.push(0);
            else
            {
                if (st.top() == 0)
                {
                    st.pop();
                    int k = st.top();
                    st.pop();
                    st.push(k + 1);
                }
                else
                {
                    int k = st.top();
                    st.pop();
                    int parent = st.top();
                    st.pop();
                    st.push(parent + 2 * k);
                }
            }
        }
        return st.top();
    }
};