class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        for(int i =0;i<n;i++)
        {
            mpp[nums[i]]=i;     
        }
        for(int i =0;i<n;i++)
        {
            int key =target-nums[i];
            if(mpp.find(key)!=mpp.end()&&mpp[key]!=i)
            {
                return {i,mpp[key]};
            }
        }
        return {};

        
    }
};