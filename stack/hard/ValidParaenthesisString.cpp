class Solution {
public:
    int scoreOfParentheses(string s) {
        int n =s.length();
        int sum=0;
        stack<int>st;
        st.push(0);
        for(int i =0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            st.push(0);
            else
            {
                if(st.top()==0)
                {
                    st.pop();
                    int k =st.top();
                    st.pop();
                    st.push(k+1);
                }
                else
                {
                    int k=st.top();
                    st.pop();
                    int parent=st.top();
                    st.pop();
                    st.push(parent+2*k);
                }
            }
        }
        return st.top();
       
        
    }
}; //this is a brute force approach

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (ch == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--;
                maxOpen++;
            }

            // Minimum possible number of open brackets
            // can never actually be negative.
            minOpen = max(0, minOpen);

            // Even the maximum possibility is negative.
            // So there is no way to make the string valid.
            if (maxOpen < 0)
                return false;
        }

        // We need some interpretation to have exactly 0
        // unmatched opening brackets.
        return minOpen == 0;
    }
};