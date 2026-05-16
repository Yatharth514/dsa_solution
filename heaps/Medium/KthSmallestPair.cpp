class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n =nums1.size();
        int m =nums2.size();
        priority_queue< pair<int,pair<int,int>>>maxh;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              maxh.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
              if(maxh.size()>k)
              {
                maxh.pop();
              }
            }
        }
        vector<vector<int>>ans;
        while(!maxh.empty())
        {
            int first=maxh.top().second.first;
            int second=maxh.top().second.second;
            ans.push_back({first,second});
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
//this is the brute force approach with tc of n*mlogk

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minh;
        for(int i =0;i<n;i++)
        {
            minh.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>>ans;
        while(ans.size()!=k&&minh.size()>0)
        {
            int first=minh.top().second.first;
            int second=minh.top().second.second;
            ans.push_back({nums1[first],nums2[second]});
            minh.pop();
            if(second+1<m)
            {
                minh.push({nums1[first]+nums2[second+1],{first,second+1}});
            }
        }
        return ans;
    }
};
//optimal sol of klogk using greedy and minheap
