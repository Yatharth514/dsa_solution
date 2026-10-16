class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n =arr.size();
        if(n==1)
        return {arr[0]};
        int l=0;
        int h=n-1;
        if(k==n)
        return arr;
        int mid=0;
        while(l<h)
        {
            mid=l+(h-l)/2;
            if(arr[mid]<=x)
            l=mid+1;
            else
            h=mid;
        }
        int piv =h;
        cout<<piv<<endl;
        vector<int>ans;   
        
        l=piv-1;
        h=piv;
        int i =1;
        if(l>=0&&h<=n-1)
            {
                if(abs(arr[l]-x)<=abs(arr[h]-x))
                {
                ans.push_back(arr[l]);
                l--;
                }
                else
                {
                    ans.push_back(arr[h]);
                    h++;
                }
            }
        else if(l>=0)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[h]);
                h++;
            }
        
        while(i<k)
        {
            if(l>=0&&h<=n-1)
            {
                if(abs(arr[l]-x)<=abs(arr[h]-x))
                {
                ans.push_back(arr[l]);
                l--;
                }
                else
                {
                    ans.push_back(arr[h]);
                    h++;
                }
            }
            else if(l>=0)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[h]);
                h++;
            }
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};