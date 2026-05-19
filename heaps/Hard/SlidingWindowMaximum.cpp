class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();
        int r=0;
        vector<int>ans;
        priority_queue<pair<int,int>>maxh;
        while(r<n)
        {
            maxh.push({nums[r],r});
            if(r>=k-1)
            {
                while(maxh.top().second<=r-k)
                {
                    maxh.pop();
                }
                ans.push_back(maxh.top().first);
            }
            r++;
        }
        return ans;
    }
};

//optimal approach
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        int n=nums.size();
        for(int i =0;i<n;i++)
        {   
            if((!q.empty())&&(q.front()<=i-k))
            q.pop_front();
            while((!q.empty())&&(nums[q.back()]<nums[i]))
            {
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1)
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};