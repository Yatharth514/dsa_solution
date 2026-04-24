class Solution {
public:
    bool judgeCircle(string moves) {
        int n =moves.length();
        int u=0;
        int d=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
            u++;
            else if(moves[i]=='L')
            l++;
            else if(moves[i]=='R')
            r++;
            else
            d++;
        }
        if((u==d)&&(l==r))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};