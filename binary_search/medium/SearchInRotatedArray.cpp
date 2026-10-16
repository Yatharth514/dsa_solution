class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        if(n==1)
        {
            if(nums[0]==target)
            return 0;
            else
            return -1;
        }
        else if(n==2)
        {
            if(nums[0]==target)
            return 0;
            else if(nums[1]==target)
            return 1;
            else
            return -1;
        }
        int l=0;
        int h=n-1;
        int piv=0;
        int mid=0;
        while(l<=h)
        {
            piv=l+(h-l)/2;
            cout<<piv<<endl;
            if(l==piv)
            break;
            if(nums[piv]>nums[n-1])
            l=piv;
            else 
            h=piv-1;
            
        }
        if(piv!=n-1&&nums[piv+1]>nums[piv])
        piv=piv+1;
        cout<<piv<<endl;
       
        if(nums[0]<=target&&target<=nums[piv])
        {
            l=0;
            h=piv;
        }
        else
        {
            l=piv+1;
            h=n-1;
        }
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]<target)
            l=mid+1;
            else
            h=mid-1;
        }
        return -1;
        
    }
};