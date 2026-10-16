class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int l=0;
        int h=n-1;
        int mid=0;
        if(arr[0]>x)
        return -1;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(arr[mid]>x)
            h=mid-1;
            else
            l=mid+1;
        }
         
        return l-1;
    }
};
