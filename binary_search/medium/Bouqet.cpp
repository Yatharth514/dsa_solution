class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        if((long long)m*k>n)
        return -1;
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i =0;i<n;i++)
        {
            l=min(l,bloomDay[i]);
            h=max(h,bloomDay[i]);
        }
        int ans=INT_MAX;
        int mid=0;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            int c=0;
            int s=0;
            for(int i =0;i<n;i++)
            {
                if(s<k)
                {
                    if(s==0)
                    {
                        if(mid>=bloomDay[i])
                        s++;

                    }
                    else
                    {
                        if(mid>=bloomDay[i]&&mid>=bloomDay[i-1])
                        s++;
                        else
                        s=0;
                        
                    }
                }
                if(s==k)
                {
                    c++;
                    s=0;
                }
            }
            if(c>=m)
            {
                if(ans>mid)
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
        


    }
};