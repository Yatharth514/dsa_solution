class Solution {
public:
bool solve(string s,int i ,int n ,int open)
{
    if(i==n)
    {
        if(open==0)
        return true;
        else
        return false;
    }
    if(open<0)
    return false;
    if(s[i]=='(')
    {
        return solve(s,i+1,n,open+1);
    }
    else if(s[i]==')')
    {
        return solve(s,i+1,n,open-1);
    }
    else
    {
        if(solve(s,i+1,n,open))
        {
            return true;
        }
        open++;
        if(solve(s,i+1,n,open))
        return true;
        open--;
        open--;
        if(solve(s,i+1,n,open))
        return true;
        else
        return false;

    }
    return false;
}
    bool checkValidString(string s) {
        int n =s.length();
        int open=0;
        return solve(s,0,n,open);
        
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