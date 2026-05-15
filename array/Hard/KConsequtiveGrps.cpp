class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n =nums.size();
        if(n%k!=0)
        return false;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it :mpp)
        {  
            int start=it.first;
            int count=mpp[start];

            if(count==0)
            continue;

            for(int i =0;i<k;i++)
            {
                if(mpp[start+i]<count)
                return false;
                mpp[start+i]=mpp[start+i]-count;
            }
            

        }
        
        return true;


        
    }
};