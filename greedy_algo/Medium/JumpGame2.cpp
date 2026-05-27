class Solution {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
        return 0;

        int cur =0;
        int maxm =0;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {   
            
            maxm=max(maxm,nums[i]+i);

            if(i==cur)
            {
                ans++;
                cur=maxm;
            }
            
            
        }
        return ans;

    }
};