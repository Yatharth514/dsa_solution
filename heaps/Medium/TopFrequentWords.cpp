class cmp {
public:
    bool operator()(pair<int,string>& a,
                    pair<int,string>& b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }

        return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        int n =words.size();
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>maxm;
        for(int i=0;i<n;i++)
        {
            mpp[words[i]]++;
        }
        vector<string>ans;
        for(auto it:mpp)
        {
            maxm.push({it.second,it.first});
            if(maxm.size()>k)
            {
                maxm.pop();
            }
        }
       
        for(int i =1;i<=k;i++)
        {
            ans.push_back(maxm.top().second);
            maxm.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};
