class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int maxm=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]+i>maxm&&i<=maxm)
            {
                maxm=nums[i]+i;
            }
            else if(i>maxm)
            {
                return false;
            }
        }
        return true;

        
    }
};