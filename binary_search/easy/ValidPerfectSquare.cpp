class Solution {
public:
    bool isPerfectSquare(int x) {
        int l=1;
        int h=x;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(mid==x/mid&&x%mid==0)
            return true;
            else if(mid>x/mid)
            h=mid-1;
            else
            l=mid+1;
        }
        return false;
    }
};