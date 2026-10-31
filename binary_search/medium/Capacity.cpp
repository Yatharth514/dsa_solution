class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n =weights.size();
        int l=INT_MIN;
        for(int i =0;i<n;i++)
        l=max(l,weights[i]);
        int h=0;
        for(int i =0;i<n;i++)
        h+=weights[i];
        
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int cap=mid;
            int d=0;
            for(int i =0;i<n;i++)
            {

                if(weights[i]<=cap&&cap>0)
                {
                    cap=cap-weights[i];
                    
                }
                else if(weights[i]>cap)
                {
                    cap=mid-weights[i];
                    d++;
                }
                

            }
            d++;
            if(d<=days)
            {
                if(ans>mid)
                {
                  ans=mid;
                }
                h=mid-1;
            }
            else
            l=mid+1;

        }
        return ans;
    }
};