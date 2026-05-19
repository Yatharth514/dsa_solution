class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();
        vector<double>ans;
        for(int i =0;i<=n-k;i++)
        {
            vector<int>box;
            for(int j=i;j<i+k;j++)
            {
                box.push_back(nums[j]);
            }
            sort(box.begin(),box.end());
            if(k%2)
            {
                ans.push_back((double)box[k/2]);
            }
            else
            {
                ans.push_back(((double)box[k/2]+(double)box[k/2-1])/2.0);
            }
        }
        return ans;
    }
};